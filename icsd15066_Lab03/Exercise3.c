/* Dionysios Theodosis A.M: 321/2015066
   Onoufrios Ntavris A.M:321/2015321
   Askisi 3                        */
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <stdbool.h>
//H domh Gia To dentro Anazitisis
struct Node{
    char country[30];
    int population;

    struct Node *left,*right;
};
//DILWSH TWN SYNARTISEWN
void insertNode(struct Node* *root,char* data1,int data2);//data1:H xwra,data2:o plithismos
void readFileNewNode(struct Node** root);
void inorder(struct Node* root);
int numberOfNodes(struct Node* root);
int maxPopulation(struct Node* root);
void countrywithP(struct Node* root,char* xwra);//xwra:h xwra pou edwse o xrhsths
int minPopulation(struct Node* root);
void emfanisiMin(struct Node* root,int value);//value:h elaxisti timi
void emfanisiMax(struct Node* root,int value);//value:h megisti timh
void deleteNode(struct Node* *root,int data);
int main(){
    //DILWSH KAI ARXIKOPOIHSH THS KEFALHS
    struct Node* root=NULL;
    //KALEI THN SYNARTHSH H OPOIA THA PROSTHESH TA DEDOMENA STO DENTRO APO TO ARXEIO
    readFileNewNode(&root);
    int t,choice;//t:VOITHITIKH METAVLITI GIA THN EKTYPWSH DEDOMENON,choice:METAVLITI POU THA PERNEI THN EPILOGH TOU XRHSTH
    char s[30];//PINAKAS XARAKTHRWN GIA TO DIAVASMA STRING
    while(1){//LOOP GIA SYNEXEIS EPANALIPSI
        //EKTYPWSH GIA TO MENU
        printf("%5sMenu\n"," ");
        printf("1)Emfanish Stoixeiwn Xwrwn\n");
        printf("2)Emfanish Plhthous Xwrwn\n");
        printf("3)Emfanish Ths Xwras Me Ton Megalutero Plhthusmo\n");
        printf("4)Emfanish Ths Xwras Me Ton Mikrotero Plhthusmo\n");
        printf("5)Emfanish Xwras Vash Plhthysmou\n");
        printf("6)Diagrafh Twn Xwrwn Me Mikrotero Plhthysmo Apo Ton Kathorismeno\n");
        printf("0)Exit\n");
        //EKXWRISI EPILOGHS XRHSTH KAI ELEGXOS EGKYROTHTAS
        do{
            printf("Dwse Epilogh:");
            scanf("%d",&choice);
         }
        while(choice!=1&&choice!=2&&choice!=3&&choice!=4&&choice!=5&&choice!=6&&choice!=0);
        //EPILOGH ENTOLHS ANALOGA ME THN APANTHSH
        switch(choice){
            case 1://EKTYPWNEI TAXINOMHMENA TA STOIXEIA TOU DENTROU
                inorder(root);
                break;
            case 2://VRISKEI TO SYNOLO TWN KOMVWN STO DENTRO
                t=numberOfNodes(root);
                printf("To Synolo Twn Xwrwn Pou Einai Apothikeumenes Einai:%d\n",t);
                break;
            case 3://VRISKEI TON MEGALUTERO PLITHYSMO STO DENTRO
                 emfanisiMax(root,maxPopulation(root));
                break;

            case 4://VRISKEI TON MUKROTERO PLITISMO STO DENTRO
                 emfanisiMin(root,minPopulation(root));
                break;
            case 5://EKTYPWNEI TON PLITHISMO THS XWRAS POU PERNEI APO TON XRHSTH
                printf("Dwse Thn Xwra Gia Na Vreis Ton Plhthusmo:");
                fflush(stdin);
                gets(s);
                countrywithP(root,s);
                break;
            case 6://DIAGRAFEI THS XWRES ME MIKROTERO PLITHISMO APO AUTON POU DINEI O XRHSTHS
                printf("Dwse Ton Elaxisto Plithismo Gia Ton Opoio Tha Yparxoun Oi Xwres Sthn Lista\n");
                fflush(stdin);
                scanf("%d",&t);
                deleteNode(&root,t);
                break;
            case 0://STAMATAEI TO PROGRAMA
                 free(root);
                return 0;
        };
    };
    return 0;
};
//SYNARTISI GIA TO DIAVASMA ARXEIOU KAI EISAGWGH TWN DEDOMENWN TOU STO DENTRO
void readFileNewNode(struct Node** root){
    FILE *fp;
    char country[30], population[30];//DILWSH 2 METAVLITWN TYPOU STRING
    fp=fopen("countries.dat", "r");
    if(fp == NULL){//ELEGXOS AN TO ARXEIO EINAI KENO
        printf("Can't open input file\n");
        return;
    };

    int p;//DILWSH METAVLITIS H OPOIA THA KRATAEI TON PLITHISMO
    while (!feof(fp)) {
        fscanf(fp, "%s %s", country, population);//DIAVAZEI THN 1H LEXH KAI THN EXWREI STO country KAI META THN 2 STO population ΤHS IDIAS SEIRAS
        p=atoi(population);//METATROPH THS LEXHS AKRIVWS SE int
        insertNode(root,country,p);//KALESMA THS SYNARTISEIS DIMIOURGEIAS NEOU KOMVOU KAI APODOSH TWN TIMWN
    };

   fclose(fp);
};
//SYNARTISI GIA THN DIMIOURGEIA NEOU KOMVOU STO DENTRO
void insertNode(struct Node **roota,char* data1,int data2){
    //AN TO DENTRO EINAI KENO
    if(*roota==NULL){
        //DESMEUH MNHMH GIA TON NEO KOMVO
        *roota=(struct Node*)malloc(sizeof(struct Node*));
        //AFOU THN DESMEUSE PERNAEI TA DEDOMENA
        if(*roota!=NULL){
            strcpy((*roota)->country,data1);
            (*roota)->population=data2;
            (*roota)->left=NULL;
            (*roota)->right=NULL;
        }
        else{//SE PERIPTWSH POU DEN MPORESE NA EKXWRISEI EKTYPWNEI TO MINIMA
      printf("den mporese na ekxwrithei h timi\n");
        };
    }
    else{//GIA NEO KOMVO AFOU YPARXH HDH ENAS
        //AN H NEA XWRA EINAI MIKROTERH THS PALIAS TOTE THN VAZEI STHN ARISTERH PLEURA
        if(strcmp(data1,((*roota)->country))<0){
            insertNode(&((*roota)->left),data1,data2);

        }//ALLIWS AN MEGALUTERH TOTE STHN DEXIA PLEURA TOU DENTROU
        else if(strcmp(data1,((*roota)->country))>0){
            insertNode(&((*roota)->right),data1,data2);
        };
    };

};
//SYNARTISI GIA THN TAXINOMHMENH EKTYPWSH TOU DENTROU
void inorder(struct Node* root){
    if (root != NULL) {
        inorder(root->left);
        printf("%s, %d \n",root->country,root->population);
        inorder(root->right);
    };
}
//SYNARTISI GIA THN EPISTROFH TOU ARITHMOU TWN KOMVWN STO DENTRO
int numberOfNodes(struct Node* root){
    if(root==NULL){//AN TO ROOT EINAI NULL TOTE VGENEI
        return 0;
    };
    return 1+numberOfNodes(root->right)+numberOfNodes(root->left);//MESW ANADROMHS PROSTHETH 1 SE KATHE EPANALIPSI
};
//SYNARTISI GIA NA VREI TON MEGALUTERO PLITHISMO STO DENTRO
int maxPopulation(struct Node* root){
  int max_value =root->population;//DILWSH METAVLITHS MAXVALUE GIA TON MEGALUTERO PLITHISMO
  //EPANALIPSI MESW ANADROMHS GIA THN EVRESH TOU MEGISTOU PLITHISMOU
  if( root->left != NULL ) {
    int temp=maxPopulation(root->left);
    if( temp > max_value ){
        max_value = temp;
    }
  }
  if( root->right != NULL ) {
    int temp = maxPopulation(root->right);
    if( temp > max_value ) {
        max_value = temp;
    }
  }
  return max_value;
}
//SYNARTISH GIA NA VREI SE POIA XWRA ANTISTOIXEI O PLITHISMOS KAI EKTYPWSH
void emfanisiMax(struct Node* root,int value){
    if(value==root->population){//AN VREI TON PLITHISMO TOTE EKTUPWNEI TO MINIMA
        printf("H Xwra Me Ton Megisto Plithismo Einai H :%s\n",root->country);
        return;
    } ;
    //SYNTHIKES GIA THN ANADROMIKH EPANALIPSH
    if(root->left!=NULL){
        emfanisiMax(root->left,value);
    };
    if(root->right!=NULL){
        emfanisiMax(root->right,value);
    };
}
//SYNARTISH GIA THN EVRESH TOU PLITHISMOU THS XWRAS
void countrywithP(struct Node* root,char* xwra){
    if(root==NULL){//AN TO ROOT EINAI NULL TOTE EKTYPWNEI TO MINIMA,STHN PERIPTWSH POU DEN VREI H EINAI KENO TO DENTRO
        printf("Den Vrethike H Xwra\n");
        return;
    }
   if(strcmp(xwra,root->country)==0){//AN TO VREI EKTYPWNEI TO MINIMA
     printf("O Pluthismos Ths Xwras %s Einai %d\n",xwra,root->population);
     return;
   };
   //SYNTHIKES GIA THN PROSPELASH TOU DENTROU
   if(strcmp(xwra,root->country)<0){
        countrywithP(root->left,xwra);
   }
   else if(strcmp(xwra,root->country)>0){
        countrywithP(root->right,xwra);
   };
};
//SYNARTISH GIA THN EURESH TOU ELAXISTOU PLITHISMOU
int minPopulation(struct Node* root) {
  int min_value =root->population;//DILWSH METAVLITIS GIA THN ELAXISTH TIMH KAI ARXIKOPOIHSH THS ME THN TIMH TOU PROTOU STOIXEIOU
  //SYNTHIKES GIA THN PROSPELASH OLWN TWN KOMVWN TOU DENTROU
  if( root->left != NULL ) {
    int temp = minPopulation(root->left);//ANADROMIKH EPANALIPSH KAI EKXWRISI TOU ELAXISTOU STO TEMO
    if( temp < min_value ){//AN TO TEMP DILADI TO PROHGOUMENO APO TO EPOMENO TOTE ANTIKATASTEI TO MIN VALUE ME TO TEMP
        min_value = temp;
    }
  }
  if( root->right != NULL ) {
    int temp = minPopulation(root->right);
    if( temp < min_value ) {
        min_value = temp;
    }
  }
  return min_value;//EPISTREFEI TON ELAXISTO PLITHISMO
}
//SYNARTISH GIA THN EURESH THS XWRAS ME AUTO TON PLITHISMO K EKTYPWSH TOU MINIMATOS GIA TON ELAXISTO PLITHISMO
void emfanisiMin(struct Node* root,int value){
    if(value==root->population){//AN VREI TON PLITHISMO STON KOMVO TOTE EKTYPWNEI TO MINIMA ME THN XWRA TOU KOMVOU
        printf("H Xwra Me Ton Elaxisto Plithismo Einai H :%s\n",root->country);
        return;
    } ;
    //ANADROMIKH EPANALIPSH GIA THN PROSPELASH TWN KOMVWN
    if(root->left!=NULL){
        emfanisiMin(root->left,value);
    };
    if(root->right!=NULL){
        emfanisiMin(root->right,value);
    };
}

//SYNARTISI GIA THN DIAGRAFH TWN XWRWN ME MIKROTERO PLITHISMO TOU DOTHENTOS
void deleteNode(struct Node* *root,int data){//DATA:O PLITHISMOS
    struct Node* temp=NULL;//DILWSH DEIKTH POU THA MAS VOITHISEI STHN DIAGRAFH
    if((*root)==NULL){
        return;
    };
    //AN O PLITHISMOS EINAI MIKROTEROS
    if((*root)->population<data){
        //GIA THN PERIPTWSH POU DEN EXEI ALLOUS KOMVOUS META
        if((*root)->left==NULL&&(*root)->right==NULL){
           free(*root);
            *root==NULL;
        }//PERIPTWSH POU EXEI MONO DEXIA KOMVOUS
        else if((*root)->left!=NULL&&(*root)->right==NULL){
            temp=(*root)->left;
            free(*root);
            *root=temp;

        }//PERIPTWSH POU EXEI MONO ARISTERA KOMVOUS
        else if((*root)->left==NULL&&(*root)->right!=NULL){
            temp=(*root)->right;
            free(*root);
            *root=temp;

        }//PERIPTWSH POU EXEI KAI DEXIA KAI ARISTERA
        else if((*root)->left!=NULL&&(*root)->right!=NULL){
            temp=(*root)->right;
            while(temp->left!=NULL){
                temp=temp->left;
            };
            free(*root);
            *root=temp;

        };

    };
    //ANADROMIKI EPANALIPSI GIA OLO TO DENTRO
  if((*root)->left!=NULL){
    deleteNode(&(*root)->left,data);
    };
 if((*root)->right!=NULL){
    deleteNode(&(*root)->right,data);};


}

