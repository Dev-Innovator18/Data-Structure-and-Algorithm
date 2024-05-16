#include<stdio.h>
#include<stdlib.h>
#define size 5
struct node{
    int data;
    struct node *next;
}*head=NULL;
struct node *head1=NULL;
struct node *head2=NULL;
struct node *create(int data){
    struct node *nn=(struct node *)malloc(sizeof(struct node));
    nn->data=data;
    nn->next=NULL;
    return nn;
}
void store(int arr[]){
    int i=0;
    FILE *fptr=fopen("file.txt","w");
    for(i=0;i<size;i++){
        fprintf(fptr,"%d ",arr[i]);
    }
    fclose(fptr);
}
void load(){
    int i=0,arr[size];
    struct node *temp=head;
    FILE *fptr=fopen("file.txt","r");
    while(fscanf(fptr,"%d",&arr[i])!=EOF){
        struct node *nn=create(arr[i]);
        if(head==NULL){
            head=nn;
            temp=nn;
        }
        else{
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=nn;
        }
    }
}
void display(){
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void odd_at_beg(){
    struct node *temp=head;
    struct node *temp1=NULL;
    struct node *temp2=NULL;
    while(temp!=NULL){
        if(temp->data%2!=0){
            struct node *nn=create(temp->data);
            if(head1==NULL){
                head1=nn;
                temp1=nn;
            }
            else{
                while(temp1->next!=NULL){
                    temp1=temp1->next;
                }
                temp1->next=nn;
            }
        }
        else{
            struct node *nn=create(temp->data);
            if(head2==NULL){
                head2=nn;
                temp2=nn;
            }
            else{
                while(temp2->next!=NULL){
                    temp2=temp2->next;
                }
                temp2->next=nn;
            }
        }
        temp=temp->next;
    }
    temp1=head1;
    temp2=head2;
    while(temp1->next!=NULL){
        temp1=temp1->next;
    }
    while(temp2!=NULL){
        temp1->next=temp2;
        temp1=temp1->next;
        temp2=temp2->next;
    }
    temp1=head1;
    while(temp1!=NULL){
        printf("%d ",temp1->data);
        temp1=temp1->next;
    }
    printf("\n");
}
void only_if_big(int key){
    struct node *temp1=head;
    while(temp1!=NULL){
        if(temp1->data>key){
            printf("%d ",temp1->data);
        }
        temp1=temp1->next;
    }
}
void main(){
    int arr[size];
    printf("Enter the elements in an array:");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    store(arr);
    load();
    display();
    odd_at_beg();
    only_if_big(2);
}