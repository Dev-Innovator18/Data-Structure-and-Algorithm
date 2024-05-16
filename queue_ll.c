#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    char name[20];
    struct node *next;
};
struct node *f=NULL;
struct node *r=NULL;
void enqueue(char name[]){
    struct node *temp=r;
    struct node *nn=(struct node *)malloc(sizeof(struct node));
    strcpy(nn->name,name);
    nn->next=NULL;
    if(f==NULL){
        f=r=nn;
        return;
    }
    temp->next=nn;
    r=nn;
}
void dequeue(){
    struct node *temp=f;
    if(f==NULL){
        printf("Queue underflow");
        return;
    }
    if(f==r){
        printf("The dequeued element is %s",temp->name);
        free(temp);
        f=r=NULL;
        return;
    }
    f=f->next;
    printf("The dequeued element is %s",temp->name);
    free(temp);
    return;
}
void display(){
    struct node *temp=f;
    while(temp!=NULL){
        printf("%s ",temp->name);
        temp=temp->next;
    }
    printf("\n");
}
void main(){
    char name[20];
    int ch,choice=1;
    while(choice){
        printf("1)Enqueue\n2)Dequeue\n3)Display\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("Enter name:");
            scanf("%s",name);
            enqueue(name);
            break;
            case 2:dequeue();
            printf("\n");
            break;
            case 3:display();
            break;
        }
        printf("Do you want to continue(1/0):");
        scanf("%d",&choice);
    }
}