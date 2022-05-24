#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *link;
};
void push(struct Node** ptr,int data);
void pop(struct Node** ptr);
int top(struct Node** ptr );
int main(){
    struct Node* p_head=NULL;
    char a[]="abcde";
    for(int i=0;i<5;i++){
        push(&p_head,a[i]);
    }

    for(int i=0;i<5;i++){
        a[i]=top(&p_head);
        pop(&p_head);
    }
    printf(" a[] = %s",a);

    return 0;
}
void push(struct Node** ptr,int data){
    struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    temp->link=(*ptr);
    (*ptr)=temp;
    
}
void pop(struct Node** ptr){
    struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
    if((*ptr)==NULL){
        return;
    }
    temp=(*ptr);
    (*ptr)=(*ptr)->link;
    free(temp);
}
int top(struct Node **ptr){
    return (*ptr)->data;
}