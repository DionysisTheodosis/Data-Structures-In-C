/*Dionysios Theodosis A.M:321/2015066
  Onoufrios Ntavris A.M:321/2015321 */
#include <stdio.h>
#include <stdlib.h>
# define N 8
//dilwsh domhs stoivas
struct Stack{
    int stackArr[N];//dilwsh pinaka N thesewn

    int top;//dilwsh metavlitis teleutais theshs
};
//synartisi gia thn ekxwrisi sstoixeiou sthn stoiva s h stoiva ,data to stoixeio
void push(struct Stack *s,int data){
    if(s->top==N-1){//elegxos gia to an einai gemath h stoiva
        printf("Den Einai Dynath H Eisagwgh Tou Stoixeiou H Stoiva Einai Gemath\n");
        return;
    };
    s->top++;//auxanei kata ena to top
    s->stackArr[s->top]=data;//ekxwrei to stoixeio ston pinaka vash dedomenwn ths stoivas
};
//synartisi gia thn diagrafh stoixeiou ths stoivas
int pop(struct Stack *s){//s h stoiva
    if(s->top==-1){//elegxos gia to an einai kenh h stoiva ,an to top einai -1 diladi kenh tote
        printf("Den Einai Dynath H Afairesh Tou Stoixeiou H Stoiva Einai Adeia\n");
        exit(1);
    };
    int stackValue=s->stackArr[s->top];//dimiourgeia metavlitis pou tha krataei thn diagrafomenh timh
    s->top=s->top-1; //meiwnei to top kata ena
    return stackValue;//epistrefei thn diagrafomenh timi
};
//synartisi gia thn provoli twn stoixeiwn ths stoivas anapoda
void reversePrint(struct Stack* s){
    struct Stack tempStack;//arxikopoihsh stoivas
    tempStack.top=-1;//arxikopohsh tou top =-1
    int value;
//gemizoume thn tempStack me ta stoixeia ths mystack
    while(s->top!=-1){
        push(&tempStack,pop(s));
    };
//gemizoume xana thn mystack opws htan
    while(tempStack.top!=-1){
        value=pop(&tempStack);//vazoume thn timh pou exei h temp stack sthn metavliti value
        push(s,value);//ekxwroume thn timi sthn myStack
        printf("%d ",value);//ektypwnoume thn timh
    };
    printf("\n");
};
//synartisi gia thn katametrisi
int katametrisi(struct Stack* s){
    struct Stack tempStack;//arxikopoihsh stoivas
    tempStack.top=-1;//arxikopohsh tou top =-1
    int sum=0;
    int value;
//gemizoume thn tempStack me ta stoixeia ths mystack
    while(s->top!=-1){
        push(&tempStack,pop(s));
    };
//gemizoume xana thn mystack opws htan
    while(tempStack.top!=-1){
        value=pop(&tempStack);//vazoume thn timh pou exei h temp stack sthn metavliti value
        push(s,value);//ekxwroume thn timi sthn myStack
        sum+=value;//prosthetoume ta stoixeia
    };
    return sum;//epistrefoume to synolo
};
//synartisi gia thn diagrafh stoixeiou
void diagrafiStoixeiou(struct Stack* s,int stackValue){
    struct Stack tempStack;//arxikopoihsh stoivas
    tempStack.top=-1;//arxikopohsh tou top =-1
    int value;//metavliti pou tha periexei thn timi
//gemizoume thn tempStack me ta stoixeia ths mystack
    while(s->top!=-1){
        push(&tempStack,pop(s));
    };
//gemizoume thn myStack me ta stoixeia xwris auto pou exei timi = me thn Stack value
    while(tempStack.top!=-1){
        value=pop(&tempStack);//afairoume apo thn tempstack to stoixeio
        if(value!=stackValue){//an to stoixeio einai diaforetiko tis stack value
            push(s,value);//gemizoume thn stoiva
        }
    };
};
//synartisi print gia na mas emfanizei ta stoixeia ths value
void Print(struct Stack* s){
    struct Stack tempStack;//arxikopoihsh stoivas
    tempStack.top=-1;//arxikopohsh tou top =-1
    int value;
//gemizoume thn tempStack me ta stoixeia ths mystack
    while(s->top!=-1){
        value=pop(s);//pernoume thn timi ths s sto teleutaio stoixeio
        printf("%d ",value);//ektypwnoume thn timi
        push(&tempStack,value);//ekxwroume to value sthn tempstack
    };
//gemizoume xana thn mystack opws htan
    while(tempStack.top!=-1){
        push(s,pop(&tempStack));//ekxwroume thn timi sthn myStack
    };
    printf("\n");
};
int main(){
    struct Stack myStack;//Arxikopoihshs stoivas
    myStack.top=-1;//arxikopohsh tou top =-1
    //Gemisma ths Stoivas myStack
    push(&myStack,1);
    push(&myStack,2);
    push(&myStack,8);
    push(&myStack,4);
    push(&myStack,5);
    push(&myStack,6);
    push(&myStack,7);
    push(&myStack,8);
    //Ektypwsh ths Stoivas
    printf("H Stoiva Einai:\n");
    Print(&myStack);
    //Ektypwsh stoivas se antistrosh seira
    printf("Ta Periexomena Ths Stoivas Se Antistrofh Seira\n");
    reversePrint(&myStack);
    //kalesma synartisis gia ton ypologismo twn stoixeiwn kai ektypwsh
    int x=katametrisi(&myStack);
    printf("To Athroisma Twn Stoixeiwn Einai:%d\n",x);
    //diagrafh sygkekrimenou stoixeiou wste na paramenoun se taxi
    int delNumber=8;
    diagrafiStoixeiou(&myStack,delNumber);
    //ektypwsh stoivas
    printf("H Stoiva Meta Thn Afairesh Tou Stoixeiou: %d ,einai:\n",delNumber);
    Print(&myStack);

return 0;
};
