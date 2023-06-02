/*Ergasthriaki Askisi 4
    Dionysios Theodosis A.M:321/2015066*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//DILWSH SYNARTISEWN
void Pinakas(int *Arr,int N);//Arr:PINAKAS,N:TO MEGETHOS TOU PINAKA
void printArr(int *Arr,int N);//Arr:PINAKAS,N:TO MEGETHOS TOU PINAKA
int InsertionSort(int *Arr,int N);//Arr:PINAKAS,N:TO MEGETHOS TOU PINAKA
int MergeSort(int *Arr, int l, int r,int sygkriseis);//ARR:PINAKS,l:O DEIKTIS STO PRWTO AKRO,r:DEIKTIS STO TELEUTAIO AKRO,sygkriseis:GIA NA KRATAEI TIS SYGKRISEIS
int Merge(int *Arr, int l, int m, int r,int sygkriseis);//ARR:PINAKS,l:O DEIKTIS STO PRWTO AKRO,r:DEIKTIS STO TELEUTAIO AKRO,sygkriseis:GIA NA KRATAEI TIS SYGKRISEIS,m:TO MESAIO STOIXEIO
void QuickSort(int *Arr,int low,int high,long long *counter);//low:DEIKTIS STO PRWTO AKRO,high:DEIKTIS STO TELEUTAIO AKRO,counter:METAVLITI GIA TIS SYGKRISEIS
void swap(int *x,int *y);//SYNARTISI GIA THN ANTISTROFH 2 METAVLITWN
int PartitionF(int *Arr,int low,int high,long long *counter);
void HeapSort(int *Arr,int N,long long *counter);
void heapify(int *Arr, int N, int index,long long *counter);//index:TO SHMEIO GIA THN SYGKRISI
int main(){
    //DILWSH METAVLITWN GIA THN METRISI TOU XRONOU
    clock_t start, end;
    float elapsed;
    float mesos_xronos=0.0;
    //DILWSH THS srand
    srand(time(NULL));
    long long mesos_arithmos_sygkrisewn=0,sygkriseis=0;
    int *Arr,N,choice;//DILWSH PINAKA,N:MEGETHOUS PINAKA,choice:GIA THN EPILOGH TOU XRHSTH
    long long counter=0;//METAVLITI GIA TIS SYGKRISEIS
    printf("\t\t*MENU*\n");
    printf("1)INSERTION SORT\n");
    printf("2)MERGE SORT\n");
    printf("3)QUICK SORT\n");
    printf("4)HEAP SORT\n");
    printf("DWSE EPILOGH [1-4]:");
    fflush(stdin);
    int flag=0;//METAVLITI GIA THN SWSTH PROVOLI TOU MINIMATOS
    do{
        if(flag!=0)printf("DWSE SWSTH EPILOGH APO [0-4]\n");//MINIMA GIA THN EISAGWGH XANA EGKYRIS TIMIS
        flag=1;
        fflush(stdin);
        scanf("%d",&choice);}//EPILOGH TAXINOMISHS APO TON XRHSTH
    while(choice!=1&&choice!=2&&choice!=3&&choice!=4);//ELEGXOS EGKYRHS EISAGWSHS
    printf("\n");
    //EISAGWGH MEGETHOUS APO TON XRHSTH
    printf("DWSE TO MEGETHOS TOY PINAKA:");
    fflush(stdin);
    scanf("%d",&N);
    //DESMEUSH MNHMHS PINAKA
    Arr=malloc(N*sizeof(int));
    //EPANALIPSI GIA 30 DIAFORETIKOUS PINAKES
    for(int i=0;i<30;i++){
        printf("\t%doS PINAKAS \n",i+1);
        Pinakas(Arr,N);//ARXIKOPOIHSH PINAKA
        printf("ARXIKOS PINAKAS: ");
        printArr(Arr,N);//EKTYPWSH PINAKA
        switch(choice){
            case 1:
                    start = clock();
                    sygkriseis=InsertionSort(Arr,N);//KALESMA THS SYNARTISHS KAI EISAGWGH TWN SYGKRISEWN
                    end = clock();
                    elapsed += ((float) (end - start)) / CLOCKS_PER_SEC;
                break;
            case 2:
                    start = clock();
                    sygkriseis=MergeSort(Arr,0,N,0);//KALESMA THS SYNARTISHS KAI EISAGWGH TWN SYGKRISEWN
                    end = clock();
                    elapsed += ((float) (end - start)) / CLOCKS_PER_SEC;

                break;
            case 3:
                    start = clock();
                    QuickSort(Arr,0,N-1,&counter);//KALESMA THS SYNARTISHS KAI EISAGWGH TWN SYGKRISEWN
                    sygkriseis=counter;
                    end = clock();
                    elapsed += ((float) (end - start)) / CLOCKS_PER_SEC;

                break;
            case 4:
                    start = clock();
                    HeapSort(Arr,N,&counter);//KALESMA THS SYNARTISHS
                    sygkriseis=counter;//APOTHIKEYSH TWN SYGKRISEWN
                    end = clock();
                    elapsed += ((float) (end - start)) / CLOCKS_PER_SEC;
                break;

        };
        //EKTYPWSH TAXINOMHMENOU PINAKA
        printf("PINAKAS META THN TAXINOMISI: ");
        printArr(Arr,N);
        //EKTYPWSH XRONOU KAI SYGKRISEWN GIA KATHE PINAKA
        printf("OI SYGKRISEIS:  %d\n",sygkriseis);
        printf("O XRONOS:  %f\n",elapsed);
        //PROSTHIKI OLWN TWN ARITHMWN SYNGKRISEWN KAI XRONWN
        mesos_arithmos_sygkrisewn+=sygkriseis;
        mesos_xronos+=elapsed;
        counter=0;//MIDENISMA TWN SYGKRISEWN
        printf("\n");
    };
    //YPOLOGISMOS MESOU XRONOU KAI MESOU ARITHMOU SYGKRISEWN
    mesos_xronos=mesos_xronos/30;
    mesos_arithmos_sygkrisewn=mesos_arithmos_sygkrisewn/30;
    //EKTYPWSH MESOU XRONOU KAI MESOU ARITHMOU SYGKRISEWN
    printf("\nMESOS ARITHMOS SYGKRISEWN: %u\n",mesos_arithmos_sygkrisewn);
    printf("MESOS XRONOS TAXINOMISIS: %f\n",mesos_xronos);
    free(Arr);//APODESMEUSH TOU DEIKTI TOU PINAKA
    Arr=NULL;
return 0;
};
//SYNARTISI ARXIKOPOIHSHS PINAKA
void Pinakas(int *Arr,int N){
    //EPANALIPSI GIA THN EISAGWGH TYXAIOU ARITHMOU APO 0-30000 SE OLA TA KELIA TOU PINAKA
    for(int i=0;i<N;i++){
        Arr[i]=rand()%30000;
    };
};
//SYNARTISI EKTYPWSHS PINAKA
void printArr(int *Arr,int N){
    printf("| ");
    for(int i=0;i<N;i++){
        printf("%d | ",Arr[i]);
    };
    printf("\n");
}
//SYNARTISI TAXINOMISIS insertionsort
int InsertionSort(int *Arr, int N){
    int sygkriseis=0;//dilwsh metavlitis gia tis sugkriseis
    for (int i=1;i<N;i++){
        int temp = Arr[i];//temp:H TIMI POU THA EINAI PROS SYGKRISH
        int j=i-1;//DILWSH METAVLITIS GIA TO PROHGOUMENO KELI
        sygkriseis++;//AUXANOUME KATA 1 TIS SYGKRISEIS
        while (temp>Arr[j]&&j>=0){//ELEGXEI AN H TIMI EINAI MEGALUTERH KAI YPARXEI PROHGOUMENO KELI TOTE
            sygkriseis++;//AUXANOUME KATA 1 TIS SYGKRISEIS
            Arr[j+1]=Arr[j];//METAKINEI THN TIMI TOU KLIDIOU STO EPOMENO
            --j;
        }
        Arr[j+1]=temp;//PROSTHIKI THS TIMIS STO KATALHLO KELI
    }
    return sygkriseis-1;//EPISTREFEI TIS SUGKRISEI -1 GIATI EXOUME METRISEI 2 FORES THN 1H SYGKRISH
}
//SYNARTISH TAXINOMISIS merge sort
int MergeSort(int *Arr,int l,int r,int sygkriseis){
        if (l<r){//ELEGXOUME KAI EKTELOUME TON KWDIKA TO DEXI AKRO MEGALUTERO TOU ARISTEROU
            int m =l+(r-l)/2;//DILWSH METAVLITIS KAI EISAGWGH TOU MESAIOU DEIKTI STOIXEIOU TOU PINAKA
            MergeSort(Arr, l, m,sygkriseis+1);//GIA TO PRWTO PARTITION
            MergeSort(Arr, m + 1, r,sygkriseis+1);//GIA TO DEUTERO PARTITION
            sygkriseis+=Merge(Arr, l, m, r,sygkriseis);//KALESMA THS SYNARTHSHS GIA THN SWSTH SYGXWNEUSH TON PINAKA ME THN SWSTH SEIRA
        }
return sygkriseis;//EPISTREFOUME TIS SYGKRISEIS
};
//SYNARTISI GIA THN SYGXWNEUSH TWN PARTITION
int Merge(int *Arr,int l,int m,int r,int sygkriseis){
    int i,j,t;//DILWSH TWN DEIKTWN,i:gia ton 1o PARTITION,j:GIA TON 2o,t:GIA TON SYGXWNEUMENO PINAKA
    int size1= m-l+1;//DILWSH KAI ARXIKOPOIHSH MEGETHOUS TOU 1ou PARTITION
    int size2 =r-m;//DILWSH KAI ARXIKOPOIHSH MEGETHOUS TOU 2ou PARTITION
    int First[size1], Second[size2];//DIMIOURGEIA TWN PARTITION,PINAKES
   //ANTIGRAFH TWN DEDOMENWN STOUS PINAKES
    for (i=0;i<size1;i++){
        First[i]=Arr[l+i];
    };
    for (j=0;j<size2;j++){
        Second[j] =Arr[m+1+j];
    };
    i = 0;//ARXIKOPOIHSH TOU DEIKTI TOU 1ou PINAKA
    j = 0;//ARXIKOPOIHSH TOU DEIKTI TOU 2ou PINAKA
    t = l;//ARXIKOPOIHSH TOU DEIKTI TOU SYGXWNEUMENOU PINAKA
    //EPANALIPSI GIA THN DIMIOURGEIA TOU SYGXWNEUMENOU PINAKA
    while (i<size1&&j<size2) {
        sygkriseis+=1;//AUXISI TOU METRITI TWN SYGKRISEWN
        if (First[i]>=Second[j]){//AN TO STOIXEIO TOU PRWTOU MEGALUTERO TOU DEYTEROU
            Arr[t]=First[i];//EKXWRISI TOU STON SYGXWNEUMENO PINAKA
            i++;//AUXISI TOU METRITI TOU 1ou
        }
        else {//ALLIWS EKXWRISI TOU STOIXEIOU TOU DEUTEROU PINAKA
            Arr[t]=Second[j];
            j++;
        }
        t++;//AUXISI TOU METRITI TOU SYGXWNEUMENOU PINAKA
    }
    //STHN PERIPTWSH POU DEN YPARXOUN STOIXEIA SE KAPOION UPOPINAKA EISAGWGH TWN STOIXEIWN TOU ALLOU PINAKA
    //GIA TON 1o
    while(i<size1) {
        Arr[t]=First[i];
        i++;
        t++;
    }
    sygkriseis+=1;//AUXISI TWN SUGKRISEWN
    //GIA TON 2o PINAKA
    while(j<size2) {
        Arr[t]=Second[j];
        j++;
        t++;
    }
    return sygkriseis;//EPISTROFH TWN SYGKRISEWN
}
//SYNARTISI TAXINOMISIS quick sort
void QuickSort(int *Arr,int low,int high,long long *counter){
    int loc;//METAVLITI GIA THN THESH TOU STOIXEIOU
    if(low<high){//EKTELI THS ENTOLES OSO O 1os DEIKTIS MIKROTEROS TOU TELEUTAIOU
        loc=PartitionF(Arr,low,high,counter);//KALESMA THS SYNARTISIS GIA THN ANAMETATHESH TWN STOIXEIWN
        QuickSort(Arr,low,loc-1,counter);//GIA TO PARTITION ARISTERA APO TO STOIXEIO POU EIXAME
        QuickSort(Arr,loc+1,high,counter);//GIA TO PARTITION DEXIA APO TO STOIXEIO POU EIXAME

    }
}
int PartitionF(int *Arr,int low,int high,long long *counter){
    int pivot=Arr[high];//DILWSH KAI ARXIKOPOIHSH TOU pivot POU THA EINAI TO SHMEIO SYGKRISEIS ME TO TELEUTAIO STOIXEIO TOU PINAKA
    int start=low-1;//ARXIKOPOIHSH METAVLITIS start
    for(int j=low;j<=high-1;j++){
        *counter+=1;//AUXHSH TWN SYGKRISEWN
        if(Arr[j]>pivot){//AN TO STOIXEIO MEGALUTERO TOU PIVOT
            start++;
            swap(&Arr[start],&Arr[j]);//ALLAZOUME TIS THESEIS
        }
    }
    swap(&Arr[start+1],&Arr[high]);//ALLAZOUME TIS THESEIS TOU epomenou stoixeiou tou start ME TO TELEUTAIO STOIXEIO TOU PINAKA
    return (start+1);//EPISTREFOUME THN EPOMENH THESH TOU START
}
//SYNARTISI ANTISTROFHS TWN METAVLITWN
void swap(int *x,int *y){//X,Y SAN DEIKTES WSTE NA KRATOUNTE OI ALLAGES
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
//AYNARTISI TAXINOMISIS HEAP SORT
void HeapSort(int *Arr,int N,long long *counter){
     for (int i=((N/2)-1);i>=0;i--){//dimiourgoume to heap
        heapify(Arr,N,i,counter);
     };
    //exagoume kata ena ta dedomena apo thn swro
    for (int i=N-1;i>0;i--) {
        swap(&Arr[0],&Arr[i]);//metakinoume ton root sto telos
        heapify(Arr,i,0,counter);//kaloume to heapify gia na meiwsoume to heap
    }
}
//Synartisi gia thn dimiourgia ths swrou
void heapify(int *Arr, int N, int index,long long *counter){
    int rootI=index; //Dilwnoume kai arxikopoioume ton root deikti
    int l=2*index+1; // l:deiktis gia to aristero paidi
    int r=2*index+2; // e:gia to dexi paidi

    //AN TO ARISTERO PAIDI EINAI MIKROTERO TOU ROOT
    if(l<N&&Arr[l]<Arr[rootI]){
        rootI=l;//STHN THESH TOU ROOT VAZOUME TO ARISTERO PAIDI
        *counter+=1;//AUXANOUME TIS SUGKRISEIS
    };
    //AN TO DEXI PAIDI EINAI MEGALUTERO TOU ROOT TOTE
    if(r<N&&Arr[r]<Arr[rootI]){
        rootI=r;//VAZOUME STO ROOT TO DEXI PAIDI
        *counter+=1;//AYXANOUME TIS SYGKRISEIS
    };
    //AN TO rootI  DEN EINAI TO ARXIKO TOTE
    if(rootI!=index){
        swap(&Arr[index],&Arr[rootI]);//ANTISTREFOUME KAI VAZOUME STHN THESH TOU PINAKA index TO STOIXEIO TOU PINAKA ROOT
        heapify(Arr,N,rootI,counter);//XANAKALOUME THN HEAPIFY GIA THN SWSTH DIAMORFWSH TOU SWROU
    };
}
