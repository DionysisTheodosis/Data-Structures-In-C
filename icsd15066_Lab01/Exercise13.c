/*DIONYSIOS THEODOSIS
    AM:321/2015066 */
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define SIZE 2000
typedef struct Movie { //h Domh ,kai xrhsimopoioume to typedef gia na paroume to typo gia eukolia
    char title[100];
    char director[40];
    char genres[40];
    int year;
}movie; //twra anti gia struct Movie aplws movie

int anazitisi(movie *movies,int size ,int etos,char *titlos); //arxikopohsh ths synartishs anazitisi,*movies:o deiktis tou pinaka domhs,size: to megethos tou pinaka,etos:h xronia ths tenias,titlos :o titlos
int eisagwgh(movie *movies,int *tempsize); //arxikopohsh ths synartishs eisagwgh,*movies:o deiktis tou pinaka domhs,*tempsize:to megethos tou pinaka kai to pername me anafora giati theloume na kratisoume thn timh
int diagrafh(movie *movies,int *tempsize,int etos,char *titlos);//arxikopohsh ths synartishs diagrafh,*movies:o deiktis tou pinaka domhs,*tempsize:to megethos tou pinaka kai to pername me anafora giati theloume na kratisoume thn timh,etos:h xronia,titlos:o titlos
void emfanish(movie *movies,int size);//arxikopohsh ths synartishs emfanish,*movies:o deiktis tou pinaka domhs,size: to megethos tou pinaka

int main(){
    movie *movies=(movie*)malloc(SIZE*sizeof(movie));//dynamikh desmeush pinaka domhs gia 2000 stoixeia
    if(movies==NULL){//elegxos gia swsth desmeysh mnhmhs
        printf("H desmeush mnhmhs apetyxe");
        exit(1);
    };
    int tempsize=0; //arxikopoihsh tou metriti megethous tou pinaka pou tha xrhsimopoioume ws megethos
    char title1[40];//arxikopoihsh metavlitis char gia thn diagrafh k anazitisi pou tha einai gia ton titlo
    int year1;//arxikopoihsh metavlitis int gia thn diagrafh k anazitisi pou tha deixnei to etos
    int x=0,y,d;//arxikopoihsh metavlitwn gia to kalesma twn synartisewn
    for(;;){ //synexeis epanalipsi , gia to programma
        int c; //arxikopoihsh metavlitis pou tha einai gia thn epilogh ekteleshs
        //ektypwsh tou menou
        printf("\t\tMENU\n");
        printf("_____________________________________\n");
        printf("1)Eisagwgh tainias\n");
        printf("2)Diagrafh tainias\n");
        printf("3)Anazitisi tainias\n");
        printf("4)Emfanish katalogou\n");
        printf("0)Exodos\n\n");
        do{ //elegxos gia to an tha dwsei swsth apanthsh o xrhsths kai ektelesh mexri na dwsei
        printf("Dwse epilogh:");
        fflush(stdin);        //katharisma buffer
        scanf("%d",&c);}
        while(c!=0 && c!=1 && c!=2 && c!=3 && c!=4);
        switch (c){ //domh epiloghs symfwna me thn apanthsh tou xrhsth
            case 1: //h periptwsh gia thn eisagwsh
                 x=eisagwgh(movies,&tempsize);//kalesma ths synartishs eisagwghs
                 //elegxos k ektypwsh katalhlou mhnymatos analogos me ti tha epistrafei
                if(x==0){
                    printf("Epityxhs prosthiki\n");
                }
                else {
                    printf("Anepityxhs prosthiki\n");
                };
                break;
            case 2://h periptwsh diagrafhs
                //ektypwsh gia na dwsei  dedomena o xrhsths
                printf("Dwse ton titlo ths tainias:");
                fflush(stdin);//katharisma buffer
                gets(title1);//eisagwgh apo to plhktrologio
                printf("\n");//allagh grammhs
                printf("Dwse to etos paragwghs ths tainias:"); //ektypwsh mhnumatos
                fflush(stdin);//katharisma buffer
                scanf("%d",&year1);//eisagwgh apo ton xrhsth ton xrono
                printf("\n");//allagh grammhs
                d=diagrafh(movies,&tempsize,year1,title1);//kalesma synartishs diagrafhs
                if(d==-1){//an h timh pou tha epistrepsei einai -1 tote ektypwnei to mhnhma oti den ginete
                    printf("Anepityxhs diagrafh tainias\n");
                }
                else {
                    printf("H tainia diagraftike epitixws\n");//alliws ektypwnei oti htan epityxeis
                }
                break;//telos ths ypotheshs
            case 3://YPOTHESH 3 GIA THN ANAZITISI
                printf("Dwse ton titlo ths tainias:");//ektypwsh mhnhmatos
                fflush(stdin);//katharisma buffer
                gets(title1);//eisagwgh apo ton xristi
                printf("\n");//allagh grammhs
                printf("Dwse to etos paragwghs ths tainias:");//ektypwsh mhnumatos
                fflush(stdin);//katharisma buffer
                scanf("%d",&year1); //eisagwgh apo ton xrhsth to etos
                printf("\n");//allagh grammhs
                y=anazitisi(movies,tempsize,year1,title1);//kalesma synartiseis anazitisis
                if(y==-1){//an h timh pou epistrefei einai -1 tote den yparxei h tenia
                        printf("Den yparxei h tainia ston katalogo\n");
                }
                else {//alliws ektypwsh tou mhnumatos
                    printf("H tainia vrethike sthn thesh :%d\n",y);
                };
                break;//telos synthikhs
            case 4://ypothesh gia thn emfanish tou pinaka
                emfanish(movies,tempsize);//kalesma synartisis emfanisis
                break;
            case 0://upothesh 0 gia thn oloklhrwsh tou programmatos
                free(movies);//apodesmeush pinaka domhs
                movies=NULL;//swsth apodesmeush
                return 0;

        };

};

return 0;
};
//synartisis eisagwshs
int eisagwgh(movie *movies,int *tempsize){
    int size=*tempsize;//dilwsh metavlitis size kai arxikopoihsh ths me thn timh ths theshs pou dixnei o deiktis tempsize
    if(size<SIZE){ //an to size einai mikrotero tou SIZE diladi tou 2000 tote
        //dikwsh metavlitwn pou tha xreiastoun gia thn eisagwgh apo ton xrhsth
        int xronos; //dilwsh metavlitis gia year
        char skinothetis[40];//metavliti gia director
        char eidos[40];//metavliti gia genres
        char titlos[100];//metavliti gia title
        printf("Dwse ton titlo ths tainias\n");//ektypwsh mhnumatos
        fflush(stdin);//katharisma buffer
        gets(titlos);//eisagwgh tou titlou apo ton xrhsth
        printf("Dwse ton skinotheti ths tainias\n");//ektypwsh mhnumatos
        fflush(stdin);//katharisma buffer
        gets(skinothetis);//eisagwgh tou director apo ton xrhsth
        printf("Dwse to eidos ths tainias\n");//ektypwsh mhnymatos
        fflush(stdin);//katharisma buffer
        gets(eidos);//eisagwgh tou genre apo ton xrhsth
        printf("Dwse to etos paragwghs ths tainias");//ektypwsh mhnymatos
        fflush(stdin);//katharisma buffer
        scanf("%d",&xronos);//eisagwgh tou year apo ton xrhsth
        int ty=0;//arxikopoihsh pou tha mas deixnei thn swsth thesh topothetiseis ths neas tainias ston pinaka domwn
        if(size==0){//synthikh gia to prwto gemisma tou pinaka
            strcpy(movies[0].title,titlos); //me thn voitheia ths strcpy pou einai sthn string.h vivliothiki dinoume thn timh sthn 1h thesh tou pinaka,mesw ths metavlitis titlos pou eishgage o xrhsths
            strcpy(movies[0].director,skinothetis);//vazoume thn timh pou edwse o xrhsths gia ton director
            strcpy(movies[0].genres,eidos);//vazoume thn timh pou edwse o xrhsths gia to genre
            movies[0].year=xronos;//vazoume thn timh pou edwse o xrhsths gia ton year
            size++; //auxanoume to megethos tou pinaka
            *tempsize=size;//auxanoume thn timh pou dixnei odeiktis pou einai eisagmenos ws anafora gia na krathsh to megethos toui pinaka
            return 0;}//telos synartishs
        else{//alliws an exei hdh timh to prwto stoixeio tou pinaka tote
            for(int i=0;i<=size;i++){//psaxnoume ston pinaka
                if(xronos==movies[i].year){//an vroume oti to etos pou edwse o xrhsths einai iso me to etos pou uparxei ston pinaka tote
                    //taxinomish deuterou epipedou
                    int temp=strcmp(titlos,movies[i].title); //arxikopoioume thn metavliti temp,k me thn vohthia ths strcmp pou kanei sygkrisei se 2 string ths dinoume thn timh ths sygkriseis
                    if(temp < 0) {//an temp <0 tote o titlos <tou movies[i].title ara prepei na eisaxthei mia thesh prin ston pinaka
                        ty=i;//opote dinoume thn thesh tou stoixeiou tou pinaka sthn ty
                        break;//exodos apoo thn epanalipsi
                    }
                    else if(temp > 0) {//alliws an einai megalytero ths movies[i].title tote
                        i++;//ayxanoume kata  1 thn thesh
                        ty=i;//thn pername sthn metavlith gia thn apodosh mias theshs meta
                        break;//exodos
                    }
                    else {//alliws shmenei oti einai ta idia opote synexizei h taxinomisi opws exei
                        printf("Einai ta idia opote ta taxinomoume opws einai");
                        break;//exodos
                    };

                }
                else if(xronos<movies[i].year){//taxinomish 1ou epipedou an o xronos tou xrhsth einai mikroteros tou uparxoun stoixeiou
                    ty=i;//eisagwgh ths thesh sthn metavliti theshs
                    break;//exodos apo thn loop
                }
                else {//alliws dinei synexeia timh tis theshs mexri na stamatisei h loop opote tha paei sthn teleutaia thesh
                    ty=i;
                };
            };
        size++;//auxhsh tou megethous tou pinaka kata 1
        for(int j=(size);j>=ty;j--){//epanalipsi gia thn metatopish twn stoixeiwn mia thesh meta apo thn thesh pou tha isagoume to stoixeio,gia auto to j=me thn teleutaia thesh kai meiwnete kata 1 mexri thn thesh tou stoixeiou
                strcpy(movies[j].title,movies[j-1].title);//sto stoixeio tou pinaka thesh j vazoume thn timh tou stoixeiou thesh j-1 gia to title
                strcpy(movies[j].director,movies[j-1].director);//sto stoixeio tou pinaka thesh j vazoume thn timh tou stoixeiou thesh j-1 gia to director
                strcpy(movies[j].genres,movies[j-1].genres);//sto stoixeio tou pinaka thesh j vazoume thn timh tou stoixeiou thesh j-1 gia to tgenres
                movies[j].year=movies[j-1].year;//sto stoixeio tou pinaka thesh j vazoume thn timh tou stoixeiou thesh j-1 gia to year
        };
        //eisagwgh twn dedomenwn pou edwse o xrhsths sthn katalili thesh pou einai h ty
        strcpy(movies[ty].title,titlos);
        strcpy(movies[ty].director,skinothetis);
        strcpy(movies[ty].genres,eidos);
        movies[ty].year=xronos;
        *tempsize=size;//dinei thn timh tou size ston tempsize wste na allaxei to megethos tou megethous tou pinaka kai na einai prosvasimo se olo to programma
        return 0;//epistrefei to 0 sthn main ara egine swsta h eisagwgh
    };}
    else {//alliws epistrefei to -1 to opoio dilwnei oti den egine h eisagwgh
        return -1;
    };
    return 0;
};
//synartisi diagrafhs
int diagrafh(movie *movies,int *tempsize,int etos,char *titlos){
   int  size=*tempsize;//dilwsh metavlitis size kai arxikopoihsh ths me thn timh ths theshs pou dixnei o deiktis tempsize
    int i=anazitisi(movies,size,etos,titlos);//kalesma ths sinartisi anazitisis gia na mas epistrepsei thn thesh tou stoixeiou pros diegrafh
    if(i==-1){//an h timh pou epistrafei einai -1 shmenei oti to shmeio den vrethike
         return -1;//etsi stamataei h synartisi k epistrefei thn timh -1
    }
    else{//alliws an vrethike
        size=size-1;//meiwnei to megethos tou pinaka
        for(int j=i;j<(size);j++){//epanalipsi apo thn thesh tou stoixeiou mexri to proteleutaio stoixeio gia na ta metatopisei ola mia thesh prin
            strcpy(movies[j].title,movies[j+1].title);//antigrafei to epomeno stoixeio tou pinaka ths metavlitis titlos sthn thesh j
            strcpy(movies[j].director,movies[j+1].director);//antigrafei to epomeno stoixeio tou pinaka ths metavlitis director sthn thesh j
            strcpy(movies[j].genres,movies[j+1].genres);//antigrafei to epomeno stoixeio tou pinaka ths metavlitis genres sthn thesh j
            movies[j].year=movies[j+1].year;//antigrafei to epomeno stoixeio tou pinaka ths metavlitis year sthn thesh j
        };
        *tempsize=size;//dinei thn timh tou size ston tempsize wste na allaxei to megethos tou megethous tou pinaka kai na einai prosvasimo se olo to programma


    };
return 0;//epistrefei sthn main me thn timh 0 pou shmenei oti egine h diagrafh
};
//synartisi anazitisi,gia anzitisi duadiki
int anazitisi(movie *movies,int size ,int etos,char *titlos ){
        int arxi=0;//arxikopoihsh metavlitis  gia to prwto shmeio tou pinaka
        int telos=size;//arxikopoihshs metavlitis gia to teleutaio shmeio tou pinaka
        while(arxi<=telos){//epanalipsi oso h arxh tha einai mikroterh = tou telous diladi tha exei elexei ola ta shmeia
            int mesi=arxi+((telos-arxi)/2);//arxikopoihsh metavlitis mesh gia to mesaio stoixeio tou pinaka
            int temp=strcmp(titlos,movies[mesi].title);//arxikopoihsh kai eisagwgh timhs sthn temp pou tha vlepei an o tiltos pou edwse o xrhsths einai idios me ton titlo tou pinaka
            if((movies[mesi].year==etos)&&(temp==0)){ //periptwsh pou kai o xronos kai o titlos einai idioi tote
                return mesi; //epistrefei thn mesh diladi thn thesh tou stoixeiou
            }
            else if(etos<movies[mesi].year){//alliws an to etos einai mikrotero tote
                telos=mesi-1;// to telos pernei thn timh ths messi -1
            }
            else{//alliws an to etos einai megalitero tote
                arxi=mesi+1;//h arxh pernei thn timh ths mesis +1 diladi tou stoixeiou meta tou mesaiou
            };
        };
    return -1;//epistrefei to -1 otan den vrethei to stoixeio
};
//synartisi emfanishs gia thnn ektypwsh tou pinaka domhs kai einai void gt den mas endiaferei na epistrepsoume kati
void emfanish(movie *movies,int size){
        for(int i=0;i<size;i++){//epanalipsi gia to megethos pinaka
            printf("Titlos:%s\n",movies[i].title);//ektypwsh tou titlou
            printf("Skinothetis:%s\n",movies[i].director);//ektypwsh tou director
            printf("Eidos:%s\n",movies[i].genres);//ektypwsh tou genre
            printf("Etos paragwghs:%d\n",movies[i].year);//ektypwsh tou year

        };
};
