#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*top=NULL;
struct node *create(int data){
    struct node *nn=(struct node *)malloc(sizeof(struct node));
    nn->data=data;
    nn->next=NULL;
    return nn;
}
void push(int data){
    struct node *temp=create(data);
    struct node *temp1=top;
    if(top==NULL){
        top=temp;
        temp1=temp;
    }
    else{
        while(temp1->next!=NULL){
            temp1=temp1->next;
        }
        temp1->next=temp;
    }
}
int pop(){
    int x;
    struct node *temp=top;
    struct node *temp1=top;
    if(top==NULL){
        printf("Stack Underflow");
        return -1;
    }
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    temp1=temp->next;
    x=temp1->data;
    temp->next=NULL;
    temp1->next=NULL;
    free(temp1);
    return x;
}
void display(){
    struct node *temp=top;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void main(){
    push(5);
    push(10);
    push(15);
    display();
    printf("Popped data is %d\n",pop());
    display();
}