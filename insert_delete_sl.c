#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    char arr[20];
    struct node *next;
};
struct node *createnode(char arr[20]){
    struct node *nn=(struct node *)malloc(sizeof(struct node));
    strcpy(nn->arr,arr);
    nn->next=NULL;
    return nn;
}
struct node *insert(struct node *head,char arr[20]){
    struct node *nn=createnode(arr);
    if(head==NULL){
        head=nn;
    }
    else{
        struct node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=nn;
    }
    return head;
}
struct node *deletepos(struct node *head,int position){
    struct node *temp=head;
    struct node *temp2=head;
    int i=2;
    while(i<position){
        temp=temp->next;
        i++;
    }
    temp2=temp->next;
    temp->next=temp2->next;
    temp2->next=NULL;
    free(temp2);
    return head;
}
struct node *deleteele(struct node *head,char arr[20]){
    struct node *temp=head;
    int count=1;
    while(temp!=NULL){
        if(strcmp(arr,temp->arr)==0){
            head=deletepos(head,count);
            break;
        }
        count++;
        temp=temp->next;
    }
    return head;
}
void display(struct node *head){
    struct node *temp=head;
    while(temp!=NULL){
        printf("%s ",temp->arr);
        temp=temp->next;
    }
}
void main(){
    struct node *head=NULL;
    int choice,ch=1,position;
    char arr[20],arr1[20];
    while(ch){
        printf("1)Insert\n2)Display\n3)Delete usint the position\n4)Delete if same name\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("Enter a word:");
            scanf("%s",arr);
            head=insert(head,arr);
            break;
            case 2:display(head);
            break;
            case 3:printf("Enter the position of the element that you want to delete:");
            scanf("%d",&position);
            head=deletepos(head,position);
            break;
            case 4:printf("Enter a string to delete:");
            scanf("%s",arr1);
            head=deleteele(head,arr1);
            break;
        }
        printf("Do you want to continue(1,0):");
        scanf("%d",&ch);
    }
}