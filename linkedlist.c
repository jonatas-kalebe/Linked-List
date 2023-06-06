#include <stdio.h>
#include<stdlib.h>
#include<string.h>

struct linkedlist{
    char name [25];
    int age;
    struct linkedlist *next;
};
typedef struct linkedlist node;

node *head = NULL;

void newNode(char name[25],int age);
void printList(void);
void insertNode(char name[25], int age, int place);
void deleteNode(int place);
void newNodeEnd(char name[25], int age);
void sortList();
void alphabeticSort();
void filterLetter(char d);
void filterAge(int a);
void makeFile();
void getFile();
void swap(node *a, node*b);
void deleteAll();
int menu();

int main(){
    int x=1,y,z;
    char n[25],d;
    while (y!=13){
        y=menu();
        switch (y){
            case 1:
                scanf("%s %d",n,&x);
                newNode(n,x);
                break;

            case 2:
                scanf("%s %d",n,&x);
                newNodeEnd(n,x);
                break;

            case 3:
                scanf("%s %d %d",n,&x,&z);
                insertNode(n,x,z);
                break;

            case 4:
                scanf("%d",&z);
                deleteNode(z);
                break;

            case 5:
                printList();
                break;
            
            case 6:
                sortList();
                break;

            case 7:
                alphabeticSort();
                break;
            
            case 8:
                scanf("%d",&z);
                filterAge(z);
                break;

            case 9:
                scanf(" %c",&d);
                filterLetter(d);
                break;

            case 10:
                makeFile();
                break;

            case 11:
                getFile();
                break;

            case 12:
                deleteAll();
                break;

            default:
                break;
        }
    }
    return 0;
}

int menu(){
    int x;
    printf("Pick and action:\n");
    printf("1) Add node at the beginning\n");
    printf("2) Add node at the end\n");
    printf("3) Add node at position x\n");
    printf("4) Delete node at position x\n");
    printf("5) Print list\n");
    printf("6) Sort list\n");
    printf("7) Alphabetic Sort\n");
    printf("8) Filter by number\n");
    printf("9) Filter by letter\n");
    printf("10) Make a file\n");
    printf("11) Read the file\n");
    printf("12) Clean\n");
    printf("13) Quit\n");
    scanf("%d",&x);
    return x;
}
void newNode(char name[25],int age){
    node *temp=malloc(sizeof(node));
    strcpy(temp->name,name);
    temp->age=age;
    temp->next=head;
    head=temp;
}
void printList(void){
    node *temp = head;
    int x=1;
    while (temp!=NULL){   
        printf("%dº - %s, %d anos\n",x++,temp->name, temp->age);
        temp=temp->next;
    }
}
void insertNode(char name[25], int age, int place){
    node *y=malloc(sizeof(node));
    node *temp=malloc(sizeof(node));
    int x=place-1;
    strcpy(temp->name,name);
    temp->age=age;
    y->next=head;
    while (x--)
    {
        y=y->next;
    }
    temp->next=y->next;
    y->next=temp;
    
}
void deleteNode(int place){
    node *y=malloc(sizeof(node));
    node *temp=malloc(sizeof(node));
    int x=place-1;
    y->next=head;
    while (x--)
    {
        y=y->next;
    }
    temp=y;
    y=y->next;    
    temp->next=y->next;
}
void newNodeEnd(char name[25], int age){
    node *temp=malloc(sizeof(node));
    node *y=malloc(sizeof(node));
    strcpy(temp->name,name);
    temp->age=age;
    y->next=head;
    while (y->next!=NULL)
    {
        y=y->next;
    }
    y->next=temp;
    temp->next=NULL;
}
void sortList(){
    node *temp= malloc(sizeof(node));
    node *temp1= malloc(sizeof(node));
    temp=head;
    while (temp->next!=NULL)
    {
        temp1=temp;
        while (temp1!=NULL)
        {
            if(temp->age>temp1->age){
                swap(temp,temp1);
            }
            temp1=temp1->next;
        }
        temp=temp->next;
    }
}
void alphabeticSort(){
    node *temp= malloc(sizeof(node));
    node *temp1= malloc(sizeof(node));
    temp=head;
    while (temp->next!=NULL)
    {
        temp1=temp;
        while (temp1!=NULL)
        {
            if(temp->name[0]>temp1->name[0]){
                swap(temp,temp1);
            }
            temp1=temp1->next;
        }
        temp=temp->next;
    }
}
void filterLetter (char d){
    node *temp = head;
    int x=1;
    while (temp!=NULL){
        if(temp->name[0]==d){
            printf("%dº - %s, %d anos\n",x++,temp->name, temp->age);
        }
        temp=temp->next;
    }
}
void filterAge(int a){
    node *temp = head;
    int x=1;
    while (temp!=NULL){
        if(temp->age==a){
            printf("%dº - %s, %d anos\n",x++,temp->name, temp->age);
        }
        temp=temp->next;
    }
}
void makeFile(){
    FILE *ptr;
    ptr=fopen("data.txt","w");
    node *temp = head;
    while (temp!=NULL){  
        fprintf(ptr,"%s %d\n",temp->name, temp->age);
        temp=temp->next;
    }
    fclose(ptr);
}
void getFile(){
    FILE *ptr;
    ptr=fopen("data.txt","r");
    while (!feof(ptr)){
        node *temp=malloc(sizeof(node));
        if(fscanf(ptr,"%s %d",temp->name,&temp->age)==EOF){
            break;
        }
        temp->next=head;
        head=temp;
    }
    fclose(ptr);   
}
void swap(node *a,node*b){
    int temp=a->age;
    a->age=b->age;
    b->age=temp;
    char tempx[25];
    strcpy(tempx,a->name);
    strcpy(a->name,b->name);
    strcpy(b->name,tempx);
}
void deleteAll(){
    while (head!=NULL)
    {
        head=head->next;
    }
}