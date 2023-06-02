/*Dionysios Theodosis
    A.M:321/2015066
Onoufrios Ntavris
    A.M:321/2015321
    Askisi 2*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Node{ //dilwsh domhs dipla syndedemenhs listas
    int productNumber;//dilwsh metavlitis gia ton kwdiko proiontos
    char* manufactore;//dilwsh dikti typou char gia to onoma tou kataskeuasth
    char* description;//dilwsh dikti typou char gia thn perigrafh
    double price;//dilwsh metavlitis double gia thn timi tou proiontos
    bool available;//dilwsh metavlitis tupou bool gia thn diathesimotita tou proiiontos
        struct Node* next;//dilwsh dikti gia ton epomeno kombo
        struct Node* prev;//dilwsh dikti gia ton prohgoumeno komvo
};
//dilwsh twn synartisewn ,se autes pou tha epexergastoume thn lista vazoume to head ws deiplo deikti
void addProduct(struct Node* *head,int productNumber,char* manufactore,char* description,double price,bool available);
void displayList(struct Node* head);
void searchProduct(struct Node* *head,int productNumber);
void deleteProduct(struct Node* *head,int productNumber);
void displaySumOfProducts(struct Node* head);
int main(){
       printf("%8sKATASTHMA%s\n","*","*");//ektyowsh minimatos gia to katasthma
       int epilogi;//dilwsh metavlitis gia thn epilogh tou xrhsth
       int kwdikos;//dilwsh metavlitis gia ton kwdiko proiontos
       double timi;//dilwsh metavlitis gia thn timi tou proiontos
       char kataskeuasths[100];//dilwsh pinaka 100 xarakthrwn
       char perigrafh[1000];//dilwsh pinaka 1000 xarakthrwn
       struct Node* head=NULL;//dilwsh kai arxikopoihsh deikti gia thn arxh ths listas
       while(true){//loop gia sunexei epanalipsi mexri na thn stamatisoume
            //ektypwsh tou menu twn epilogwn
            printf("1)Add Product\n");
            printf("2)Display Products\n");
            printf("3)Search Product\n");
            printf("4)Delete Product\n");
            printf("5)Display The Number Of The Products\n");
            printf("0)Exit\n");
            do{//elegxos an exei dosei o xrhsths apodekth timi
                printf("Dwse Epilogh:");
                fflush(stdin);
                scanf("%d",&epilogi);//eisagwgh ths epiloghs tou xrhsth
            }
            while(epilogi!=0&&epilogi!=1&&epilogi!=2&&epilogi!=3&&epilogi!=4&&epilogi!=5);
            switch(epilogi){//wste na kanei analoga me to ti exei dwsei
                case 1://gia thn dhmiourgeia neou komvou
                    printf("dwse kwdiko proiontos: ");
                    fflush(stdin);
                    scanf("%d",&kwdikos);//eisagei ton kwdiko
                    printf("\n");
                    printf("dwse timi proiontos: ");
                    fflush(stdin);
                    scanf("%lf",&timi);//eisagei thn timi
                    printf("\n");
                    printf("Dwse Kataskeuasth: ");
                    fflush(stdin);
                    fgets(kataskeuasths,sizeof(kataskeuasths),stdin);//eisagei to alfarithmitiko gia to onoma tou kataskeuasth
                    printf("Dwse Perigrafh: ");
                    fflush(stdin);
                    fgets(perigrafh,sizeof(perigrafh),stdin);//eisagei to alfarithmitiko gia thn perigrafei
                    addProduct(&head,kwdikos,kataskeuasths,perigrafh,timi,true);//kalei thn synartisi dimiourgeias komvou
                    break;
                case 2:
                    displayList(head);//kalh thn synartisi gia thn ektypwsh ths listas
                    break;
                case 3:
                    printf("Dwse Ton Kwdiko Tou Proiontos Pros Anazitisi:");
                    fflush(stdin);
                    scanf("%d",&kwdikos);
                    searchProduct(&head,kwdikos);//kalh thn sunartisi gia thn anazitisi tou proiontos symfwna me ton kwdiko
                    break;
                case 4:
                    printf("Dwse Ton Kwdiko Tou Proiontos Pros Afairesh:");
                    fflush(stdin);
                    scanf("%d",&kwdikos);
                    deleteProduct(&head,kwdikos);//kalh thn synartisi gia thn diagrafh tou proiontos symfwna me ton kwdiko
                    break;
                case 5:
                    displaySumOfProducts(head);//kalei thn synartisi gia thn ektypwsh tou plithous twn proiontwn
                    break;
                case 0:
                    free(head);//eleytherwnei to head
                    return 0;//kai termatizei
            };
       };
return 0;
};
//synartisei gia thn dimiourgeia proiontos - komvou listas
void addProduct(struct Node* *head,int productNumber,char* manufactore,char* description,double price,bool available){
    if(*head==NULL){//gia an to head einai mhden tote eisagei ton komvo sthn 1h thesh
        *head=(struct Node*)malloc(sizeof(struct Node*));//desmeush mnhmhs listas
        (*head)->productNumber=productNumber;//arxikopoiei ton kwdiko tou proiontos
        int length=snprintf( NULL, 0, "%s",manufactore);//etsi vlepoume to megethos tou alfarithmitikou
        (*head)->manufactore=(char *)malloc(length);//desmeuoume toso xwro gia thn prosthiki tou alfarithmitikou sthn lista
        strcpy((*head)->manufactore,manufactore);//prpsthetoume ton kataskeuasth sthn lista
        length=snprintf( NULL, 0, "%s",description);
        (*head)->description=(char *)malloc(length);
        strcpy((*head)->description,description);//thn perigrafh
        (*head)->price=price;//prosthetoume thn timi
        (*head)->available=available;//eisagoume thn diathesimothta
        (*head)->next=NULL;//kanoume to head na deixnei to null
        (*head)->prev=NULL;//epishs kai ton prohgoumeno null
    }
    else{
       struct Node* current=NULL;//
       current=*head;
       while(current!=NULL){//gia na elexoume an yparxei proion me ton idio kwdiko an nai den ginete h eisagwgh
            if(current->productNumber==productNumber){
                printf("Adynath H Eisagwgh Tou Proiontos Dioti Yparxei Hdh\n");
                return;
            };
            current=current->next;
       };
       struct Node* newNode=NULL;
       newNode=(struct Node*)malloc(sizeof(struct Node*));//desmeush komvou
       int  length=snprintf( NULL, 0, "%s",manufactore);
       newNode->manufactore=(char* )malloc(length+1);
       strcpy(newNode->manufactore,manufactore);
       length=snprintf( NULL, 0, "%s",description);
       newNode->description=(char* )malloc(length+1);
       strcpy(newNode->description,description);
       newNode->available=available;
       newNode->productNumber=productNumber;
       newNode->price=price;
       current=*head;
       while(current!=NULL){//eisagegh tou komvou sto telos ths listas
            if(current->next==NULL){
                current->next=newNode;
                newNode->next=NULL;
                newNode->prev=current;
                return;
            };
            current=current->next;
       };
    };
}
//synartisi gia thn provoli twn stoixeiwn ths listas
void displayList(struct Node* head){
    if(head==NULL){//elegxei an h lista einai kenh
        printf("H Lista Einai Kenh\n");
        return;
    }
    else{
        struct Node* current=NULL;//arxikopoihsh dikti
        current=head;
        printf("H Lista Einai:\n");
        while(current!=NULL){//eoanalipsi gia olous tou komvous
            //ektypwnei ta stoixeia
            printf("*******************\n");
            printf("Product Number:%d\n",current->productNumber);
            printf("Manufactore : ");
            puts(current->manufactore);
            printf("Description: ");
            puts(current->description);
            printf("Available %s\n",current->available?"YES":"NO");
            printf("Price: %0.2f\n",current->price);
            current=current->next;
        };
         printf("*******************\n");
    };
}
//synartisi gia thn anazitisi tou proiontos
void searchProduct(struct Node* *head,int productNumber){
    if(head==NULL){//el;egxoume an h lista einai kenh
        printf("H Lista Einai Kenh\n");
        return;
    }
    else{
        struct Node* current=NULL;
        current=*head;
        if((*head)->productNumber==productNumber){//an to proion einai sthn prwth thesh tote ektypwnoume mono ta stoixeia tou
            //ektypwsh twn dedomenwn
            printf("\nStoixeia Proiontos:\n");
            printf("Manufactore : ");
            puts((*head)->manufactore);
            printf("Description: ");
            puts((*head)->description);
            printf("Available %s\n",(*head)->available?"YES":"NO");//analogos thn epistrefomenh timh apo thn bool ektypwnei yes h no
            printf("Price: %0.2f\n",(*head)->price);
        }
       else{//se periptwsh pou vriskete se thesh allh ektos tou head
            struct Node* q=NULL;
            current=*head;
            while(current->next!=NULL){//prospelash olwn twn komvwn
                if(current->productNumber==productNumber){// na vrei to proionmexri na vrei to proion tote ektypwnei ta stoixeia tou
                    fflush(stdout);
                    printf("Stoixeia Proiontos:\n");
                    printf("Manufactore : ");
                    puts(current->manufactore);
                    printf("Description: ");
                    puts(current->description);
                    printf("Available %s\n",current->available?"YES":"NO");
                    printf("Price: %0.2f\n",current->price);
                    break;
                };
                current=current->next;
            };
        //an to current pou exei vgei apo ton prohgoumeno komvo exei diaforetiko arithmo tote den vrike to stixeio gt exoume valei na vgei an current->nex ==null kai oxi current
            if(current->productNumber!=productNumber){
                printf("Den Yparxei To Proion Sthn Lista\n");
                return;
            };
            while(current!=NULL&&current->prev!=NULL){//epanalipsi gia olous tous komvous
                if(current->prev->prev!=NULL&&current->next==NULL){//an to stoixeio pou vrike einai sto teleutaio komvo gia thn diasxisei ths listas
                    q=current->prev;
                    current->prev->prev->next=current;
                    q->next=current->next;
                    current->prev=q->prev;
                    q->prev=current;
                    current->next=q;
                }
                else if(current->prev->prev!=NULL&&current->next!=NULL){//an to stouxeio den einai ston teleutaio komvo kai den einai kai meta apo to head
                    q=current->prev;
                    current->prev->prev->next=current;
                    current->next->prev=q;
                    q->next=current->next;
                    current->prev=q->prev;
                    q->prev=current;
                    current->next=q;
                };
                if(current->prev->prev==NULL&&current->next!=NULL){//an to stouxeio einai meta to head kai den einai ston teleutaio komvo
                    q=*head;
                    q->next=current->next;
                    current->next=q;
                    current->prev=NULL;
                    q->prev=current;
                    current->next=q;
                    *head=current;
                    break;
                }
                else if(current->prev->prev==NULL&&current->next==NULL){//an to stoixeio einai meta to head kai einai ston teleutaio kombo
                    q=*head;
                    *head=current;
                    q->next=NULL;
                    (*head)->prev=NULL;
                    q->prev=*head;
                    (*head)->next=q;
                    break;
                };
            };
        };

    };
};
//synartisi gia thn diagrafh tou proiontos
void deleteProduct(struct Node* *head,int productNumber){
    if(*head==NULL){
        printf("H Lista Einai Kenh\n");
        return;
    }
    else{
        struct Node* current=NULL;
        struct Node* temp=NULL;
        current=*head;
        if((*head)->productNumber==productNumber){
            temp=*head;
            if((*head)->next==NULL){
                free(*head);
                *head=NULL;
            }
            else{
            *head=(*head)->next;
             free(temp);
            (*head)->prev=NULL;
            };
        }
       else{
            current=*head;
            while(current!=NULL&&current->productNumber!=productNumber){
                current=current->next;
            };
            if(current->productNumber!=productNumber){
                printf("Den Yparxei Proion Me Auton ton Kwdiko Adynamia  Afaireshs\n");
                return;
            };
            if(current->next!=NULL){
                temp=current;
                current->next->prev=current->prev;
                current->prev->next=current->next;
                free(temp);
            }
            else if(current->next==NULL){
                temp=current;
                current->prev->next=NULL;
                free(temp);
            };
        };
        printf("To proion Diagraftike\n");
    };

}
//synartisi gia thn ektypwsh tou arithmou twn proiontwn
void displaySumOfProducts(struct Node* head){
    if(head==NULL){//elegxoume an h lista einai kenh
        printf("H Lista Einai Kenh\n");
        return;
    }
    else{
        struct Node* current=NULL;
        current=head;

        int sum=0;
        while(current!=NULL){//prospelash olwn twn komvwn
            current=current->next;
            sum++;//auxisi tou metriti
        };
        free(current);
        printf("To Plithos Twn Proiontwn Einai: %d\n",sum);//ektypwsh tou athroismatos twn proiontwn

    };
}


