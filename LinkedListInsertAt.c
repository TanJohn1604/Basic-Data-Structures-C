#include<stdio.h>
#include<stdlib.h>

void insert(int n,int x);
void print();

struct Node{
    int data;
    struct Node *link;
};
struct Node* p_head;
int main(){
    p_head=NULL;
    int n=1,x=1;
    while(n){
    printf("Nhap so can chen \n");
    scanf("%d%d",&n,&x);
    insert(n,x);
    print();
    }
    return 1;
}

void insert(int n,int x){
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
        for(int i=0;i<x-1;i++){
            temp1=temp1->link;
        }
        if(x==0){
            temp->link=p_head;
            p_head=temp;
        }
        else{
            temp->link=temp1->link;
            temp1->link=temp;
        }
        


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