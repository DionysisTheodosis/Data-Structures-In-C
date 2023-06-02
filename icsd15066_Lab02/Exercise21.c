/*Dionysios Theodosis
    A.M:321/2015066
Onoufrios Ntavris
    A.M:321/2015321
    Askisi 2*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
struct Node{//dilwsh listas
    int data;

    struct Node* next;
};
//dilwsh twn synartisewn
void addNode(struct Node* *head,int data);
const char* toString(struct Node* head);
void deleteList(struct Node* *head);
void deleteElement(struct Node* *head,int data);
bool containsList(struct Node* head,int data);
void countList(struct Node* head);
void countElement(struct Node* head,int data);
int getElement(struct Node* head,int data);//data thesh komvou
int firstLocationList(struct Node* head,int data);
int lastLocationList(struct Node* head ,int data);
void removeDuplicates(struct Node* *head,int data);
int main(){
    struct Node* head=NULL;//dilwsh pointer tupou node head
    //desmeush mnhmhs kai arxikopoihsh tou prwtou node
    head=(struct Node*)malloc(sizeof(struct Node));
    head->data=8;
    head->next=NULL;
    //dimiourgia listas fthinousa seiras
    addNode(&head,5);//kalh thn synartish gia na prosthesh komvo kata fthinousa taxinomisi
    addNode(&head,6);
    addNode(&head,7);
    addNode(&head,10);
    printf("H Lista Einai:\n");//ektypwsh minimatos gia thn lista
    puts(toString(head));//kalh thn sunartisi gia thn ektypwsh ths listas
    //kalei thn synartisei gia thn ektypwsei twn kovwn ths listas
    countList(head);
    addNode(&head,6);//prosthike tou 6 gia na yparxei 2 fores sthn lista
    //kalei thn synartisi gia na dei poses fores periexete to stoixeio (6 se auth thn periptwsh) sthn lista
    countElement(head,6);
    //kalei thn  synartisi gia na diagrapsh twn komvo pou periexei to 5
    deleteElement(&head,5);
    printf("H Lista Meta Thn Diagrafh Tou 5 Einai:\n");//ektypwsh minimatos gia thn lista
    puts(toString(head));//kalh thn sunartisi gia thn ektypwsh ths listas
    //Kalei thn synartisi gia na vrei ton arithmo pou vriskete ston komvo 2
    printf("O Arithmos Pou Vriskete Sthn  %dh Thesh Ths Listas Einai: %d\n",2,getElement(head,2));
    //KALEI THN SYNARTISI KAI EMFANIZEI TO APOTELESMA GIA THN PRWTH EMFANISI TOU ARITHMOU 6 SE AUTH THN PERIPTWSH
    printf("H Prwth Emfanish Tou Arithmou %d Sthn Lista Einai Sthn Thesh: %d\n",6,firstLocationList(head,6));    //deleteList(&head);
    //KALEI THN SYNARTISI KAI EMFANIZEI TO APOTELESMA GIA THN TELEUTAIA EMFANISI TOU ARITHMOU 6 SE AUTH THN PERIPTWSH
    printf("H Teleutaia Emfanish Tou Arithmou: %d Einai Sthn Thesh: %d\n",6,lastLocationList(head,6));
    //KALEI THN SYNARTISI KAI EKTYPWNH ANALOGA ME THN EPISTREFWMENH TIMH
    printf("Periexei H Lista Ton Arithmo 8?\n%s\n",containsList(head,8)?"true":"false");
    printf("Periexei H Lista Ton Arithmo 13?\n%s\n",containsList(head,13)?"true":"false");
    //AFAIREI TA DIPLASTOIXEIA POU VRISKONTAI STHN LISTA SE AUTH THN PERIPTWSH TO 6
    printf("Afairei Tis Pollaples Emfaniseis Tou Stoixeiou 6 sthn Periptwsh\n");
    removeDuplicates(&head,6);
    printf("H Lista Meta Thn Diagrafh Twn Diplotypwn Einai:\n");//ektypwsh minimatos gia thn lista
    puts(toString(head));//kalh thn sunartisi gia thn ektypwsh ths listas
    //DIAGRAFEI THN LISTA
    deleteList(&head);
    printf("H Lista Einai:\n");//ektypwsh minimatos gia thn lista
    puts(toString(head));//kalh thn sunartisi gia thn ektypwsh ths listas
return 0;
};
//synartisi gia thn dimiourgia neou komvou
void addNode(struct Node* *head,int data){
    if(*head==NULL){//elegxos gia na dei an einai kenh lista kai an nai termatizei to programma
      printf("H Lista Einai Kenh To Programma Tha Termatistei\n");
      exit(1);
    }
    else
    {
        struct Node* newP=NULL;//dimiourgia deikti
        newP=(struct Node*)malloc(sizeof(struct Node*));//desmeush mnhmhs gia ton komvo
        newP->data=data;//ekxwrei to data
        newP->next=NULL;//kai to next na deixnei null
        struct Node* cu=NULL;
        struct Node* temp=NULL;
        cu=*head;//kanoume ton cu na dixnei sto head
        if((*head)->data<=newP->data){//an einai megalutero tou head data tote ton vazei sthn arxh
            newP->next=*head;
            *head=newP;
        }
        else{
            while(cu->next!=NULL&&cu->next->data>newP->data){//epanalipseimexri na vrei komvo me mikroterh timi
                cu=cu->next;
            };
            newP->next=cu->next;//topotheth to ton komvo na deixnei sto epomeno tou komvou pou vrike
            cu->next=newP;//kai ton komvo pou vrike na deixnei ston komvo
        };
    };
};
//synartisi gia na epistrefei ta dedomena ths listas ws string
const char* toString(struct Node* head){
    if(head==NULL){//elegxos an h synartisi einai kenh kai an nai tote termatizei
        printf("H Lista Einai Kenh To Programma Tha Termatistei\n");
        exit(1);
    }
    else{
        struct Node *current=NULL;//dilwsh deixti kai arxikopoihshtou,tha einai gia na mas deixnei ton komvo epexergasias
        current=(struct Node*)malloc(sizeof(struct Node*));//desmeysh nnhmhs,ousiastika den xreiazotan alla xwris auto gia kapoion logo den etrexe
        current=head;//prosthiki tou head sto current
        int size=0;//dilwsh metavlitis size to opoio to synolo twn stoixeiwn
        while(current!=NULL){//epanalipsi gia na vroume to plithos
            size++;
            current=current->next;
        };
        size=(size*2)-1;//ypologismos tou size tou alfarithmitikou me to synolo stoixeiwn *2-1 gt tha eisagoume kai to ,
        char str[size],koma=',';//dilwsh pinaka char ,kai char  koma
        current=head;
        *str='\0';//arxikopoioume to str ws keno
        while(current!=NULL){//mexri to current na ginei null dilladi na prospelasei olh thn lista
            int t=current->data;//dilwnoume metavliti t pou tha pernei thn timi tou stoixeiou ths listas
            int length = snprintf( NULL, 0, "%d", t );//wste na pairnei to megethos twn xarakthrwn tou data
            char s[length+1];//dilwsh pinaka char
            itoa(t,s,10);//metatropi tou int se char kai apothikeush sto string
            strcat(str,s);//antigrafh to string tou xarakthra sto string
            current=current->next;
            if(current!=0){//prosthetei to , oso exei next
                strcat(str,",");
            };
        };
        char* y=str;//dilwsh neou deikti wste na mporei na epistrafei sthn main to string
        return y;//epistrofh tou string
    };
};
//synartisi gia thn diagrafh ths listas
void deleteList(struct Node* *head){
    if(*head==NULL){//elegxoume an einai kenh h lista
       printf("H Lista Einai Kenh To Programma Tha Termatistei\n");
    }
    else{
       struct Node* current=NULL;//dilwnoume deikti pou tha dixnei ton komvo
       struct Node*currentNext=NULL;//dilwnoume deikti pou tha dixnei ston epomeno
       current=*head;//kanoume to current na deixnei sto head
       while(current!=NULL){//oso to current einai diaforetiko tou null diagrafei olous tou komvou xekinwnta apo to head
           currentNext=current->next;
           free(current);
           current=currentNext;
        };
        *head=NULL;//diagrafei ton 1o komvo
        free(*head);
    };
};
//synartisi gia thn diagrafh stoixeiou me timi data
void deleteElement(struct Node* *head,int data){
    if(*head==NULL){//elegxos an to head einai nulll
        printf("H Lista Einai Kenh To Programma Tha Termatistei\n");
    }
    else{
        struct Node* current=NULL;//dilwsh deikti pou tha deixnei se komvo
        struct Node* currentNext=NULL;//dilwsei deikti pou tha dixnei ston epomeno komvo
        current=*head;//to current tha deixnei opou to head
        if((*head)->data==data){//an h timi periexete sto head tote
            current=(*head)->next;//vazoume to current ws ton 2 komvo
            currentNext=*head;//vazoume sto currentnext thn timi tou head
            *head=current;//kanoume ton 2o komvo ws head
            free(currentNext);//eleutherwnoume thn thesh tou prohgoumenou head
        }
        else{
            while(current!=NULL){//synthiki gia na prospelasei olous tous komvous
                if(current->next->data==data){//an to data einai iso me ton epomeno komvo
                    currentNext=current->next;//vazoume sto currentnext to next
                    current->next=current->next->next;//tote vazoume ton current na deixnei ston methepomeno
                    free(currentNext);//diagrafh ths desmeumenhs mnhmhs
                    break;
                }
                else{
                    current=current->next;//allazei komvo
                };
            };
        };
    };
};
//synartisei tupou bool gia to an uparxei to stoixeio
bool containsList(struct Node* head,int data){
    if(head==NULL){//elegxoume an h lista den einai kenh
        printf("H Lista Einai Kenh To Programma Tha Termatistei\n");
        exit(1);
    }
    else{
        struct Node* current=NULL;//dilwnoume deikti pou tha deixnei ton komvo
        current=head;
        while(current!=NULL){//epanalipsi gia thn prospelash olwn twn komvwn
            if(current->data==data){ //an vrethei epistrefei tru
                return true;
            };
            current=current->next;
        };
        return false;//an oxi tote false
    };
};
//synartisi gia na epistrefei posous kombous exei h lista
void countList(struct Node* head){//edw den xreiazete o diplos deiktis sto head gt den tha tropopoihsoume thn lista
    if(head==NULL){//elegxoume an h lista einai kenh
        printf("H Lista Einai Kenh To Programma Tha Termatistei\n");
    }
    else{
        struct Node* current=NULL;//dimiourgia deikti current
        current=head;
        int numberOfNodes=0;//arxikopoihsh metavlitis gia ton arithmo twn komvwn
        while(current!=NULL){//prospelash olwn twn komvwn
            numberOfNodes++;//autxisei ths metavlitis kata 1
            current=current->next;
        };
        printf("H Lista Periexei %d Komvous\n",numberOfNodes);//ektypwsh tou plithous twn komvwn
    };
};
//synartisi pou metraei tis emfanisei enos stoixeiou
void countElement(struct Node* head,int data){
    if(head==NULL){//elegxoume an h lista einai kenh
        printf("H Lista Einai Kenh To Programma Tha Termatistei\n");
    }
    else{
        struct Node* current=NULL;//dilwnoume deikti pou tha dixnei ton komvo
        current=head;//arxikopoihsh tou idio me ton head
        int NumberOfElements=0;//dilwsh kai arxikopoihsh ths metavlitis gia to athroisma
        while(current!=NULL){//gia thn prospelash olwn ton komvwn
            if(current->data==data){//an to data uparxei ston komvo
                NumberOfElements++;//auxisei ths metavlitis kata 1
            };
            current=current->next;
        };
        printf("O Arithmos %d Emfanizete %d Fores\n",data,NumberOfElements);//ektypwnei tis emfaniseis
    };
};
//synartisi gia na epistrefei thn timi symfwna me thn thesh tou komvou pou exei parei
int getElement(struct Node* head,int data){
    if(head==NULL){//elegxoume an h lista einai kenh kai exodos apo to programma
        printf("H Lista Einai Kenh To Programma Tha Termatistei\n");
        exit(1);
    }
    else{
        struct Node* current=NULL;//dilwsh kai arxikopoihsh deikti
        current=head;
        int position=1;//dilwsh metavlitis pou tha dixnei thn thesh tou komvou
        while(current!=NULL&&position!=data){//prospelash mexri na vrei ton komvo me thn thesh pou exoume
            current=current->next;
            position++;//auxisei tou metriti ths theshs
        };
        if(current==NULL){//an to current einai mhden diladi den yparxei komvos me auth thn thesh tote stamataei to programma
            printf("Den Yparxei Ayth H Thesh Listas\n");
            exit(1);

        };
        return current->data;//epistrefei thn timi tou komvou sthn sygkekrimenh thesh
    };
};
//sinartisi gia thn epistrofh ths thesh ths prwths emfanisis tou arithmou sthn lista
int firstLocationList(struct Node* head,int data){
    if(head==NULL){//elegxoume an h lista einai kenh
       printf("H Lista Einai Kenh To Programma Tha Termatistei\n");
        exit(1);
    }
    else{
        struct Node* current=NULL;//dilwsh deikti current
        current=head;
        int position=1;//metavliti h opoia tha thn xrhsimopoihsoume ws deikth theshs
        while(current!=NULL&&current->data!=data){//prospelash ths lista ws otu prospelathei olh h vrei komvo me auth thn timi
            current=current->next;
            position++;//auxisi metriti theshs
        };
        if(current==NULL){//an to current =nnull diladh oti prospelathike olh h lista xwris match
            printf("Den Yparxei Autos O Arithmos Sthn Lista\n");//ektypwnei minima enhmerwshs
            exit(1);//stamataei to programma
        };
        return position;//epistrefei thn thesh tou komvou
    };
};
//synartisi gia thn epistrofh ths teleutaias theshs emfanisis tou stoixeiou sthn lista
int lastLocationList(struct Node* head,int data){
    if(head==NULL){//elegxoume an h lista einai kenh
        printf("H Lista Einai Kenh To Programma Tha Termatistei\n");
        exit(1);//exodos apo to programma
    }
    else{
        struct Node* current=NULL;//dilwsh deikti pou tha deixnei se komvo
        current=head;//arxikopoihsh tou ws head
        int position=0;//metavliti pou tha dixnei thn thesh tou komvou
        int counterOfPositions=1;//metritis gia ton arithmo tou komvou
        while(current!=NULL){//prospelash olwn twn komvwn
            if(current->data==data){//an h timi tou komvou einai idia me thn timi pou exoume dwsei
                position=counterOfPositions;//sthn thesh vazoume thn thesh tou komvou
            };
            counterOfPositions++;//metritis thesh komvou
            current=current->next;//current = me ton epomeno komvo
        };
        if(position==0){//elegxoume an exei vrei ton arithmo alliws
            printf("Den Uparxei Autos O Arithmos Sthn Lista\n");//ektypwnoume minima enhmerwshs
            exit(1);//exodos apo to programma
        };
        return position;//epistrefoume thn thesh
    };
};
//sinartisi gia thn diagrafh twn diplotupwn stoixeiwn
void removeDuplicates(struct Node* *head,int data){
    if(head==NULL){//elegxoume an h lista einai kenh
        printf("H Lista Einai Kenh To Programma Tha Termatistei\n");
        exit(1);
    }
    else{
        struct Node* current=NULL;//dilwsh deikti pou tha dixnei ton komvo
        struct Node* currentNext=NULL;//dilwsh deikti gia ton epomeno komvo
        current=*head;
        int flag=0;//dilwsh metavlitis ws flag gia na doume an exoume diplotipa
        while(current->next!=NULL){//prospelash olwn twn komvwn
            if(current->next->data==data&&flag==0){//elegxos an yparxei komvos me auto to data kai to flag mhden diladi prwth emfanisi tou data tote toflag =1
                flag=1;
            }
            else if(current->next->data==data&&flag==1){//alliws an to flag ==1 tote dixnei oti exei xanauparxei auth h timi kai diagrafh ton komvo
                currentNext=current->next;
                current->next=current->next->next;
                free(currentNext);//apodesmeush mnhmhs komvou
            }
            else{
                current=current->next;//allazei to current na deixnei ston epomeno komvo
            }

        };
        if(flag==0){//an to flag paramenei akoma 0 tote ektypwnei oti o arithmos den periexete sthn lista
            printf("Den Yparxei Autos O Arithmos Sthn Lista\n");
        };
    };
};
