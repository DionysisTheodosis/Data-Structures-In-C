/*DIONYSIOS THEODOSIS
    AM:321/2015066 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Synartisi arxikopoihshs kai desmeushs pinaka
int *Array(int x){
    int *arr;
    //Dynamikh Desmeush tou pinaka
    arr= (int*)malloc(x*sizeof(int));
    //elegxos an exei ginei swsta h desmeush
    if(arr==NULL){
        printf("H desmeush mnhmhs apetuxe");
        exit(1); // stamataei to programma
        };
    //tha paragei tyxaious arithmous vash tou Am mou
    srand((long) 2015066);
    arr[0]=1+(rand() % (x));  //Eisagei enan tuxaio arithmo apo to 0-N sto 1o stoixeio tou pinaka
     //Eisagwgei arithmwn ston pinaka
    for(int i=0;i<x;i++){
        arr[i]=1+rand()%(x);
    };
    return arr; //epistrofh tou pinaka
}
// 1h synartisi seiriakis anazitisis
void seiriakh_anazhthsh1(int*p,int key, int st){    //h 1h thesh tou pinaka , key to k,st to plithos tou pinaka
    int i,thesi=0;    //arxikopoihsh tou i ektos wste na krataei tin timh k ektos ths for
    //epanalipsi gia thn euresh tou key
    for( i=0;i<st;i++){
        thesi+=1;
        if(key==p[i]){  // elegxos an to key einai to idio me to stoixeio tou pinaka
            printf("O arithmos vrethike sthn thesh: %d\n",i); //ektypwsh thesis
            break;  //exodos apo thn epanalipsi
        };
    };
    //elegxos gia to an den vrethike to stoixeio kai emfanisei mhnumatos
    if((thesi==st) && (key!=p[thesi-1])){
        printf("Den vrethike o arythmos\n");
    };
    printf("O arithmos twn sygkrisewn einai:%d",thesi); //ektypwsei wn sygkrisewn
};
// 2h synartisi seiriakis anazitisis
void seiriakh_anazhthsh2(int *p,int key,int st){    //h 1h thesh tou pinaka , key to k,st to plithos tou pinaka
    int *thesh,t=0,f=0; //dilwsh kai arxikopoihsh metavlitwn thesh pinakas gia tis theseis,t o deikths tou pinaka f mia flag metavliti
    thesh=(int *)malloc(1*sizeof(int));//desmeush mnhmhs gia pinaka me 1 giati den xeroume akoma to akrives plithos
    for(int i=0;i<st;i++){
        //gia thn prwth emfanisi tou arithmou
        if(key==p[i] && f==0){
                thesh[t]=i;
                f=1;
        }
        else if((key==p[i]) && (f==1)){ //gia thn deuterh emfanish tou arithmou
                t+=1;
                thesh=(int *)realloc(thesh,(t+1)*sizeof(int));  //epektinoume thn mnhmh kata 1 gia thn apothikeush neas theshs
                //elegxos an exei ginei swsta h desmeush
                if(thesh==NULL){
                    printf("H desmeush mnhmhs apetuxe");
                    exit(1); // stamataei to programma
                };
                thesh[t]=i; //eisagwgh ston pinaka theshs thn thesh
        };
    };
    if (t==0 && f==1){ //elegxos an exei vrei stoixeio kai an einai h prwth fora
        printf("O arithmos vrethike 1 fora sthn thesh:%d",thesh[t]);
    }
    else if(f==1) {//elegxos an exei vrei arithmo panw apo mia fora
        printf("O arithmos vrethike %d fores stis theseis:",t+1);
        for(int i=0;i<=t;i++){  //ektypwsh twn thesewn
            printf("%d\t",thesh[i]);
        }}
    else { //alliws ektypwsh oti den vryke
        printf("O arithmos den vrethike\n");
    };
    free(thesh);//apodesmeush pinaka apo thn mnhmh

    };

int main(){

    //Dilwsh metavlitwn N gia to plithos kai dilwsh pinaka
    int N,*Arr;
    //Entolh gia na eisagei o xrhsths to megethos tou pinaka
    printf("Dwse to plithos twn stroixeiwn toy pinaka:\n");
    scanf("%d",&N);
    //kalesma synartisis gia arxikopoihsh kai desmeush pinaka
    Arr=Array(N);
    //Eisagwgh tyxaiou arithmou sthn metavliti k
    srand(time(NULL));;
    int k=1 +rand()%(N);
    //kalesma seiriakhs anazitisis 1
    printf("\t\t\t\tSeiriakh Anazhthsh me telos thn emfanish tou k\n");
    seiriakh_anazhthsh1(Arr,k,N);
    //kalesma seiriakhs anazitisis 2
    printf("\n\t\t\t\tSeiriakh Anazhthsh me telos afotou ektypwthoun oles oi emfaniseis tou r\n");
    seiriakh_anazhthsh2(Arr,k,N);
    //Apodesmeush tou pinaka apo thn mnhmh
    free(Arr);
    Arr=NULL; //to vazoume ws NULL giati mono me thn free synexisei na deixnei se mia mh uparkth thesh mnhmhs
return 0;
};
