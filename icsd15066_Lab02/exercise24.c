//Onoufrios Ntavris,A.M:321/2015150
//Theodosis Dionysios,A.M:321/2015066
#include <stdio.h>//dhlwsh vivlio8hkwn gia tis sunarthseis poy 8a xrhsimopoihsw
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TRUE 1//dhlwsh kauolikwn metavlhtwn pou isxuoun gia oles tis synarthseis mou
#define FALSE 0
#define SIZE 25


typedef struct client//dhlvsh domhs gia ton pelath ths trapezas
{
    char name[40];
    int number;
    time_t time;
} Client;//sunwnumo tou struct client gia na mhn to grafv sunexeia pio katw ston kwdika mou

void client_init(Client *p,int size);//dhlwsh prwtotupwn twn sunarthsewn pou xrhsimopoiw
int client_empty(int);
int client_full(int,int);
void Eisagwgh(Client *p,int *start,int *finish,int *num,int *pl,int size);
void E3agwgh(Client *p,int *start,int finish,int *num,int *pl);
void Display(Client *p,int start,int finish);
void Time(time_t time);

int main ()//arxh main synarthshs
{
    int choice,i,start,finish,num=0,pl=0;//dhlwsh metavlhtwn
    Client pin[SIZE];
    client_init(pin,SIZE);//arxikopoihsh tou pinaka pelatwn
    start=-1;//arxikopoihsh deiktwn start kai finish gia thn oura mou
    finish=0;
    printf("-----Menu Trapezas------");//ektupwsh enos menu poy 8a leei sto xrhsth tis epiloges pou exei
    printf("\n1)Eisodos pelath sthn oura anamonhs");
    printf("\n2)E3odos Pelath apo thn oura anamonhs");
    printf("\n3)Emfanish stoixeiwn pelatwn pros e3uphrethsh");
    printf("\n4)Plh8os pelatwn pros e3uphrethsh");
    printf("\n5)E3odoS");
    printf("\nTi 8eleis na kaneis? ");
    scanf("%d", &choice);
    if(choice<1 || choice>5)//elegxos gia thn epilogh tou xrhsth kai klhsh twn katallhlwn sunarthsewn
    {
        do
        {
            printf("h epilogh pou dwsate den einai swsth!!3anadwste apo 1-5!!");
            scanf("%d", &choice);
        }
        while (choice<1 || choice>5);
    }
    while (choice != 5)
    {
        if(choice==1)
        {
            Eisagwgh(pin,&start,&finish,&num,&pl,SIZE);
        }
        else if(choice==2)
        {
            E3agwgh(pin,&start,finish,&num,&pl);
        }
        else if(choice==3)
        {
            Display(pin,start,finish);
        }
        else
        {
            printf ("oi pelatew pou einai sthn oura anamonhs einai: %d",pl);
        }
        printf("\nTi 8eleis na kaneis? ");
        scanf("%d", &choice);
    }
    return 0;
}

void client_init(Client *p,int size)//sunarthsh gia arxikopoihsh toy pinaka poy pernaw san orisma
{
    int i;
    for(i=0; i<size; i++)
    {
        strcpy(p[i].name,"keno");
        p[i].number=-1;
        p[i].time=0;
    }
}



int client_empty(int x)//sunarthsh pou elegxei an o pinakas einai adeios kai epistrefei TRUE/FALSE analogws
{
    return x==-1;
}

int Client_full(int x,int y)//Sunarthsh pou elegxei an o pinakas einai gematos
{
    if(y==x-1)
    {
        return TRUE;
    }
    else if(y==SIZE && x==0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void Eisagwgh(Client *p,int *start,int *finish,int *num,int *pl,int size)//sunarthsh pou kanei thn eisagwgh enos pelath sthn trapeza(ton pinaka pelatwn)
{
    if(*finish == SIZE-1 && *start>0)//elegxos gia to pote 8a kanei to finish na 3ekinaei pali apo thn arxh tou pinaka
    {
        *finish=0;
    }
    if(Client_full(*start,*finish)==TRUE)//elegxos gia to an o pinakas einai gematos
    {
        printf("\nh lista anamonhs einai gemath perimenete na fugei kapoios");
    }
    else//an den einai kanv eisagwgh tou pelath
    {

        *pl=*pl+1;//metrhths pou metraei posous pelates exw
        *start=0;//arxikopoihsh tou startmolis mpei o prwtos pelaths
        printf("Dwse to onoma tou pelath: ");
        fflush(stdin);//ka8arismos tou stdin gia na mhn mou petaei errors
        fgets(p[*finish].name,sizeof(p[*start].name),stdin);//arxikopoihsh twn stoixeiwn tou pelath pou deixnei o deikths *finish
        p[*finish].number=*num;
        p[*finish].time=time(0)+7200;
        *num=*num+1;
        printf("\n%d %d",*start,*finish);//ektupwsh twn deiktwn start kai finish giati kati den paei kala
        if (*finish<=SIZE-1)//elegxos gia to pote 8a au3anw to finish
        {
          *finish=*finish+1;
        }
    }
}

void E3agwgh(Client *p,int *start,int finish,int *num,int *pl)//ulopoish ths sunarthshs gia thn e3odo you pelath apo thn trapeza
{
    time_t temp1,w8;//dhlwsh metavlhtwn
    Client temp;//proswrinh metavlhth gia thn apo8hkeush tou stoixeiou pou diagrafw gia na to ektupwnw sthn o8onh
    if(client_empty(*start)==TRUE)//elegxos gia to an o pinakas pelatwn einai adeios
    {
        printf("\nh lista anamonhs einai adeia!!");
    }
    else//alliws paw kai kanw e3agwgh tou pelath pou deixnei o start deikths
    {
        *pl=*pl-1;
        temp=p[*start];
        printf("o pelaths %s efuge.\n",temp.name);
        strcpy(p[*start].name,"keno");//arxikopoihsh tou stoixeiou pou diagrafw pali
        p[*start].number=-1;
        p[*start].time=0;
        *start=*start+1;//au3hsh tou deikth start gia na paw ston epomeno pelath sthn oura anamonhs
        temp1=time(0)+7200;//upologismos tou pragmatikou xronou anamonhs tou ka8e pelath prin kanei e3odo
        w8=temp1-p[*start].time;
        printf("kai eixe xrono anamonhs : \n");
        Time(w8);
    }
    if(*start==finish)//an o deikths start ginei isos me ton deikth finish 3ana3ekina ton apo thn arxh
    {
        *start=0;
    }
     printf("\n%d %d",*start,finish);
}

void Time(time_t time)//ulopoihsh sunarthshs pou upologizei thn wra pou eiserxetai o ka8e pelaths sthn trapeza
{
    int minutes,seconds,hours,minutes2,hours2;
    minutes=time/60;
    hours=minutes/60;
    seconds= time % 60;
    minutes2=minutes%60;
    hours2=hours%24;
    printf("%d:%d:%d\n",hours2,minutes2,seconds);
}



void Display(Client *p,int start,int finish)//ulopoihsh sunarthshs pou ektupwnei ta stoixeia tou ka8e pelath sthn o8onh
{
    if(client_empty(start)==TRUE)
    {
        printf("den uparxei kapoios pelaths");
    }
    else
    {
        int i;
        printf("Ta stoixeia twn pelatwn pros e3uphrethsh einai:\n");
        for(i=start; i<finish; i++)
        {
            printf("%sme ari8mo %d mphke stis :",p[i].name,p[i].number);
            Time(p[i].time);
        }
    }
}
