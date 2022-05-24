#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *link;
};
void enqueue(int x);
void deenqueue();

struct Node *p_front=NULL;    
struct Node *p_rear=NULL;
int main(){

    
    return 0;
}
void enqueue(int x){
    struct Node * temp=NULL;
    temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=x;
    temp->link=NULL;
    if(p_front==NULL && p_rear==NULL ){
        p_front=p_rear=temp;
        return;
    }
    p_rear->link=temp;
    p_rear=temp;
}
void deenqueue(){
    struct Node *temp=p_front;
    if(p_front==NULL){
        return;
    }
    if(p_front==p_rear){
        p_front=p_rear=NULL;
    }
    else{
        p_front=p_front->link;
    }
    free(temp);
}
int front(){
    return p_front->data;
}