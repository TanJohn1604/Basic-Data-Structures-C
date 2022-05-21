#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *link;
};

int main(){
    //con trỏ lưu điah chỉ node đầu tiên
    struct Node *A;
    A=NULL;
    //tạo node temp
    struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=2;
    temp->link=NULL;
    //gán địa chỉ node đầu tiên cho con trỏ chính (A)
    A=temp;
    
    //hàm duyệt đến node cuối cùng,tức là node với link = NULL
    struct Node *temp1=A;
    while(temp1->link !=NULL){
        temp1=temp1->link;
    }
    
    return 0;
}