/*DIONYSIOS THEODOSIS
    AM:321/2015066 */
#include<stdio.h>
#include<stdlib.h>
//Askisi 1
void antistrofi(int *arr1,int arxi,int telos){//arr1 o deiktis tou pinaka,arxh deiktis poy tha krataei thn thesh tou pinaka,telos to megethos tou pinaka
    if (arxi < telos){  //tha ginete h ektelesh oso h deiktis ths arxis einai mikroteros tou telous
        int temp = arr1[arxi]; //vazoyme sth temp to aristero stoixeio
        arr1[arxi] = arr1[telos]; //sto prwto keli tou pinaka vazoume to teleutaio
        arr1[telos] = temp; //kai sto teleutaio to prwto

        antistrofi(arr1, arxi + 1, telos - 1);//xanakaloume thn synartisi gia na synexisi
    };
};
//Askisi 2
void duadiki(int *arr,int k,int arxi, int telos){ //arr o deiktis tou 1ou stixoiou tou pinaka , k auto pou psaxnoume,arxi h prwth thesh tou deikth tou pinaka,telos to megethos to opoio allazei san deiktis

    if(arxi<=telos){ //o diktis arxi einai mikroteros tou telous
        int mesi=arxi +(telos-arxi)/2; //arxikopoioume to messaio stixeio
        if(arr[mesi]==k){ //elegxos an einai idia
                printf("vrethike");//ektypwsh mhnymatos
                return; //epistrofh sthn main
        };
        if(k<arr[mesi]){//an to k einai mikrotero tou mesaiou stoixeiou
                return duadiki(arr,k,arxi,mesi-1); //epistrefoume to telos ws thn mesi-1
        };

             //alliws sth arxi vazoume to mesaio stoixeio tou pinaka giati to k>arr[mesi]
           return  duadiki(arr,k,mesi+1,telos); //epistrefoume thn arxi ws tthn mesh+1
        };
    printf("den vrethike"); //epistrofh katalilou mhnymatos
    return;//epistrofh sthn main
    };

int main(){
    //Askisi 1
    printf("1h Askhsh \n\n"); //ektypwnei to shmeio arxhs ths prwths askhshs
    int Arr1[6]={2,7,6,5,8,9}; //arxikopoioume enan pinaka Arr1 6 stoixeiwn
    printf("O Arxikos pinakas:\n"); //ektypwnoume to mhnuma
    for(int i=0;i<6;i++){ //ektypwsh pinaka
        printf("|%d",Arr1[i]);
    };
    printf("|\n");//ektypwsh allaghs grammhs
    int n=sizeof(Arr1)/sizeof(Arr1[0]);//metavliti gia to megethos tou pinaka,epeidh einai karfwta ta dedomena gia na fanei o kwdikas
    int start=0;//gia ton deikth ths 1hs theshs tou pinaka
    antistrofi(Arr1,start,n-1); //kalesma ths synartisis kai ekxwrisi twn metavlitwn,ton pinaka ,ton deikti ths arxh kai ton deikth telous-1
    printf("O pinakas meta tin antistrofi:\n");//ektypwsh mhnymatos
    for(int i=0;i<6;i++){ ////ektypwsh tou antistrepsimou pinaka
        printf("|%d",Arr1[i]);
    };
    printf("|\n");
    //Askhsh 2
    printf("\n\n2h Askhsh\n\n");
    int  Arr2[7]={2,4,6,7,9,10,11};//arxikopoihsh pinaka me statheres
    //kwdikas pou deixnei oti tha to vrei
    printf("Periptwsh pou uparxei o arithmos\n");
    int k=7; //o arithmos pou psaxnoume
    int first=0;//arxikopoihsh metavlitis deikti 1hs thesh tou pinaka
    int Arraysize=sizeof(Arr2)/sizeof(Arr2[0]);//arxikopoihsh timhs megethous tou pinaka
    printf("Exodos diadikhs:");
    duadiki(Arr2,k,first,Arraysize);//kalesma diadikis synartisis,dinontas ton pinaka,thn 1h thesh kai to megethos tou
    //kwdikas pou to kleish den tha yparxei ston pinaka
    printf("\nPeriptwsh pou den uparxei o arithmos\n");
    k=12; //o arithmos pou psaxnoume
    first=0;//arxikopoihsh metavlitis deikti 1hs thesh tou pinaka
    Arraysize=sizeof(Arr2)/sizeof(Arr2[0]);//arxikopoihsh timhs megethous tou pinaka
    printf("Exodos diadikhs:");
    duadiki(Arr2,k,first,Arraysize); //kalesma diadikis synartisis,dinontas ton pinaka,thn 1h thesh kai to megethos tou
return 0;
};
