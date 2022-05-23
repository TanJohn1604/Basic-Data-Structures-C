#include<stdio.h>
#include<stdlib.h>
//địa chỉ con trỏ
//giá trị con trỏ = địa chỉ trỏ tới
//* địa chỉ = nội dung của tại địa chỉ
struct BstNode
{
    int data;
    struct BstNode *left;
    struct BstNode *right;
};

int search(struct BstNode *ptr,int data);
void insert(struct BstNode **ptr,int data);
void newnode(struct BstNode **ptr,int data);

int findheight (struct BstNode *ptr);

int main(){
    struct BstNode *p_head=NULL;
    insert(&p_head,10);
    insert(&p_head,8);
    insert(&p_head,9);
    printf("height = %d", findheight(p_head));
    return 1;
}

void insert(struct BstNode **ptr, int data){
    if(*ptr==NULL){
        newnode(ptr,data);
    }
    else if((*ptr)->data>=data){
        insert(&((*ptr)->left),data);
    }else{
        insert(&((*ptr)->right),data);
    }
}
void newnode(struct BstNode **ptr,int data){
    *ptr=(struct BstNode *)malloc(sizeof(struct BstNode));
    (*ptr)->data=data;
    (*ptr)->left=NULL;
    (*ptr)->right=NULL;
}
int findheight(struct BstNode *ptr){
    if(ptr==NULL){
        return -1;
    }
    return 1+(findheight(ptr->left)>findheight(ptr->right)?findheight(ptr->left):findheight(ptr->right));
}
