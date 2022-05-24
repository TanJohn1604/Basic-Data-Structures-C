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
void preorder(struct BstNode *ptr);
void inorder(struct BstNode *ptr);// tìm theo thứ tự từ nhỏ tới lớn
void postorder(struct BstNode *ptr);
int IsBST(struct BstNode *ptr);
int IsSubLess(struct BstNode *ptr,int data);
int IsSubGreater(struct BstNode *ptr,int data);

int main(){
    struct BstNode *p_head=NULL;
    insert(&p_head,10);
    insert(&p_head,8);
    insert(&p_head,9);
    printf("true or false %d",IsBST(p_head));
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
void preorder(struct BstNode *ptr){
    if(ptr==NULL){
        return;
    }
    printf("%d ",ptr->data);
    preorder(ptr->left);
    preorder(ptr->right);
}
void inorder(struct BstNode *ptr){
    if(ptr==NULL){
        return;
    }
    preorder(ptr->left);
    printf("%d ",ptr->data);
    preorder(ptr->right);
}
void postorder(struct BstNode *ptr){
    if(ptr==NULL){
        return;
    }
    preorder(ptr->left);
    preorder(ptr->right);
    printf("%d ",ptr->data);
}
int IsBST(struct BstNode *ptr){
    if(ptr==NULL){
        return 1;
    }
    if(IsSubLess((ptr->left),ptr->data)&&
    IsSubGreater((ptr->right),ptr->data) &&
    IsBST(ptr->left)&&
    IsBST(ptr->right) ){
        return 1;
    }
    else{
        return 0;
    }
}
int IsSubLess(struct BstNode *ptr,int data){
    if(ptr == NULL){
        return 1;
    }
    if(ptr -> data <= data &&
    IsSubLess(ptr->left,data)&&
    IsSubLess(ptr->right,data)){
        return 1;
    }else{
        return 0;
    }
}
int IsSubGreater(struct BstNode *ptr,int data){
    if(ptr == NULL){
        return 1;
    }
    if(ptr -> data > data &&
    IsSubLess(ptr->left,data)&&
    IsSubLess(ptr->right,data)){
        return 1;
    }else{
        return 0;
    }
}
