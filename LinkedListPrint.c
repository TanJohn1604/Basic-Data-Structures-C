#include<stdio.h>
#include<stdlib.h>


struct Node{
    int data;
    struct Node *link;
};
struct Node* p_head;

void insert(int n);
void print();
//hàm đệ qui
void printfor(struct Node *p);
void printrev(struct Node *p);


int main(){
    p_head=NULL;
    int n=1;
    while(n){
    printf("Nhap so can chen \n");
    scanf("%d",&n);
    insert(n);
    print();
    }
    printfor(p_head);
    printf("\n");
    printrev(p_head);
    return 1;
}

void insert(int n){
    if(p_head==NULL){
        struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
        temp->data=n;
        temp->link=NULL;
        p_head=temp;
    }
    else{
        struct Node *temp= (struct Node*)malloc(sizeof(struct Node));
        temp->data=n;
        temp->link=NULL;

        struct Node *temp1=p_head;
        while(temp1->link!=NULL){
            temp1=temp1->link;
        }
        temp1->link=temp;


    }
}
void print(){
    struct Node *temp1=p_head;
    printf("day so linkedlist la ");
    while(temp1!=NULL){
        printf("  %d",temp1->data);
        temp1=temp1->link;
    }
    printf("\n");
}
void printfor(struct Node *p){
    if(p==NULL){
        return;
    }
    printf("%d ",p->data);
    printfor(p->link);
}
void printrev(struct Node *p){
    if(p==NULL){
        return;
    }
    printrev(p->link);
    printf("%d ",p->data);

}
