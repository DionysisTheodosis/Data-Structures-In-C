/*DIONYSIOS THEODOSIS
    AM:321/2015066 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Synartisi arxikopoihshs pinaka
int *Array(int x){ //to x einai to megethos tou pinaka
    int *arr;
    arr=(int*)malloc(x*sizeof(int));//desmeush mnhmhs tou pinaka
    //elegxos an exei ginei swsta h desmeush
    if(arr==NULL){
        printf("H desmeush mnhmhs apetuxe");
        exit(1); // stamataei to programma
        };
    //arxikopoihsh pinaka
    arr[0]=0; //arxikopoihsh 1hs theshs
    for(int i=1;i<x;i++){ //epanalipsi gia thn arxikopoihsh twn thesewn tou pinaka symfwna me to A[i]=A[i-1]+i
            arr[i]=arr[i-1]+i;

    };
    return arr; //epistrofh pinaka sthn main
};
//Synartish syriakhs anazitisis se taxinomhmeno pinaka
int seiriakh_anazhthsh(int *arr,int key,int x){ //arr deiktis tou pinaka Arr,key einai to k, x to megethos tou pinaka
    int i=0;//dilwnoume to i
    int sygkrisi=1; //arxikopoihsh ths metavlitis twn sygkrisewn
    while(i<x){ //epanalipsi oso to i einai mikrotero tou megethous x tou pinaka
         if(key==arr[i]){   //an to key=k diladi an to vrei
            printf("vrethike\n");
            return sygkrisi; //epistrefei ton arithmo twn sygkrisewn
        }
        else if (key<arr[i]){ //elegxos an to k einai mikrotero tou stoixeiou tou pinaka k afou einai taxinomimenos tote stamataei
        printf("den vrethike1\n");
           return sygkrisi;//epistrofh twn sygkrisewn
        }
        else {
            i++;//auxisi tou deikti twn keliwn tou pinaka
            sygkrisi++ ;//ayxhsh ths sygkriseis kata 1
        };
    };
    printf("Den htan dynath h eyresh tou k\n"); //mhnuma an den vrethike o arithmos
    return sygkrisi; //epistrofh twn sygkrisewn
};
//synarthsh dyadikhs anazhthshs
int dyadiki_anazhthsh(int *arr,int key,int x){ //arr deiktis tou pinaka Arr,key einai to k, x to megethos tou pinaka
        int arxi=0;  //Arxikopoioume thn arxh ws tos deikth tou prwtou stoixeiou tou pinaka
        int telos=x-1; //arxikopoioume to telos ws to deikth tou teleuteou stoixeiou tou pinaka
        int i=1;// arxikopoihsh tou i pou tha mas dwsei tis sygkriseis
        while(arxi<=telos){
            int mesi=arxi+((telos-arxi)/2);// arxikopoihsh ths metavlitis me to mesaio deikth tou pinaka
            if(arr[mesi]==key){ //an h to mesaio stoixeio tou pinaka einai iso me to k
                return i; //epistrefei tis sygkriseis
            }
            else if(key<arr[mesi]){//an to k einai mikrotero tou mesaiou stoixeiou
                telos=mesi-1; //tote to telos ginete to stoixeio prin to mesaio tou pinaka
            }
            else{
                arxi=mesi+1; //alliws sth arxi vazoume to mesaio stoixeio tou pinaka giati to k>arr[mesi]
            };
            i++; //ayxisi twn sygkrisewn
        }
        return i; //epistrofh twn sygkrisewn
};
//seiriakh synarthsh se mh taxinomhmeno pinaka gia thn symplhrwsh tou pinaka twn xronwn
int seiriakh_anazhthsh2(int *arr,int key,int x){    //arr deiktis tou pinaka Arr,key einai to k, x to megethos tou pinaka
        int sygkrisi=1; //arxikopoihsh ths metavlitis twn sygkrisewn
        for(int i=0;i<x;i++){   //epanalhpsh me vash to megethos tou pinaka gia thn anazhthsh
                if(key==arr[i]){ //an to k einai iso me to stoixeio tou pinaka
                    return sygkrisi; //tote epistrefei tis sygkriseis
                };
                sygkrisi++; //auxanei kata ena tis sygkriseis
        };
        return sygkrisi; //epistrefei tis sygkrisei se periptwsh pou den vrethike to k
};

int main(){
    int *Arr,k,N; //dilwsh metavlitis pinaka ws pointer, dilwsh tou k:tou stoixeiou  pou anazhtame,N:megethos pinaka
    int a=0; //arxikopoihsh k dhlwsh ths metavlitis deikth gia this epanalipsis gia diafora megethoi pinaka
    while(a<5){//epanalhpsh mexri 5 fores gia diaforetika megethoi pinaka
        printf("DWSE N:"); //ektypwsei minimatos gia eisagwgh apo to plhktrologio
        scanf("%d",&N);//eisagwgh megethous pinaka
        int i=0; //arxikopoihsh k dhlwsh ths metavlitis deikth gia this epanalipsis gia diafores times tou k
        Arr=Array(N); //kaloume thn synarthsh pinaka gia thn dimiourgia tou
        srand(time(NULL)); //dilwsh srand
        double xronosA=0,xronosB=0,xronosC=0; //dilwsei metavlitwn kai arxikopoihsh tous pou tha apothikeuoun to xrono ektelesh,xronosA gia thn seiriakhse taxinomimeno,xronosB gia thn dyadiki,xronosC  gia seiriaki se mh taxinomimeno
        int sygkriseisB=0,sygkriseisA=0,sygkriseisC=0; //dilwsei metavlitwn kai arxikopoihsh tous pou tha apothikeuoun to arithmo twn sygkrisewn ,sygkriseisA  gia thn seiriakh se taxinomimeno,sygkriseisB gia thn dyadiki,sygkriseisC  gia thn seiriakh se  mhtaxinomimeno
        while (i<100){ // epanalipsi mexri 100 fores gia diafores times tou k
            int k=1 +rand()%(N); // dinoume mia tyxaia timi sto k
            clock_t start, end; //dilwsh ths synartishs clock
            double elapsed; //dilwsh ths metavlitis elapse pou tha exei to xrono ths ekteleshs
            //kwdikas seiriakhs anazhthshs se taxinomhmeno pinaka
            start = clock(); //arxikos xronos
            sygkriseisA=seiriakh_anazhthsh(Arr,k,N)+sygkriseisA; //kalesma ths seiriakhs anazhthshs kai eisagwgh twn sygkrisewn
            end = clock();//telikos xronos
            elapsed = ((double) (end - start)) / CLOCKS_PER_SEC; //ypologismos tou xronou afairontas apo ton arxiko ton teliko ana deuterolepto
            xronosA=elapsed+xronosA;//eisagwgh tou xronou sthn metavliti  pou einai gia ton xrono ths seiriakhs
            //kwdikas dyadikhs anazhthshs
            start = clock();
            sygkriseisB=dyadiki_anazhthsh(Arr,k,N)+sygkriseisB;//kalesma ths dyadikhs anazhthsh kai eisagwgei twn sygkrisewn
            end = clock();
            elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
            xronosB=elapsed+xronosB; //eisagwgh tou xronou sthn metavliti  pou einai gia ton xrono ths dyadikhs
            //kwdikas seiriakhs anazhthshse mh taxinomhmeno pinaka
            start = clock(); //arxikos xronos
            sygkriseisC=seiriakh_anazhthsh2(Arr,k,N)+sygkriseisC; //kalesma ths seiriakhs anazhthshs kai eisagwgh twn sygkrisewn
            end = clock();//telikos xronos
            elapsed = ((double) (end - start)) / CLOCKS_PER_SEC; //ypologismos tou xronou afairontas apo ton arxiko ton teliko ana deuterolepto
            xronosC=elapsed+xronosC;//eisagwgh tou xronou sthn metavliti  pou einai gia ton xrono ths seiriakhs
            i++; //ayxisi dikti forwn
        };
        printf("  Megethos Pinaka:%d\n",N); //ektypwsh tou megethous tou pinaka
        printf("\tMesos arithmos sygkrisewn gia thn seiriaki anazitisi se taxinomhmeno pinaka:%d\n",sygkriseisA/100);//ektypwsh k upologismos tou mesou orou twn sygkrisewn ths seiriakhs anazhthsh
        printf("Mesos xronos anazhthshs gia thn seiriaki anazitisi se taxinomhmeno pinaka:%f\n",xronosA/100);//ektypwsh k upologismos tou mesou xronou ths seiriakhs anazhthshs
        printf("\tMesos arithmos sygkrisewn gia thn duadikh anazitisi se taxinomhmeno pinaka:%d\n",sygkriseisB/100);//ektypwsh k upologismos tou mesou orou twn sygkrisewn ths dyadikis anazhthshs
        printf("Mesos xronos anazhthshs gia thn duadikh anazitisi se taxinomhmeno pinaka:%f\n",xronosB/100); //ektypwsh k ypologismos tou mesou xronou ths dyadikhs anazhthshs
        printf("\tMesos arithmos sygkrisewn gia thn seiriakianazitisi se mh taxinomhmeno pinaka:%d\n",sygkriseisC/100);//ektypwsh k upologismos tou mesou orou twn sygkrisewn ths seiriakhs anazhthsh
        printf("Mesos xronos anazhthshs gia thn seiriaki anazitisi se mh  taxinomhmeno pinaka:%f\n",xronosC/100);//ektypwsh k upologismos tou mesou xronou ths seiriakhs anazhthshs
        a++; //auxisi dikti forwn
        free(Arr);//apeleutherwsh Arr tou pinaka diladi
        Arr=NULL;//swsth apodesmeush
    };
    return 0;
};
