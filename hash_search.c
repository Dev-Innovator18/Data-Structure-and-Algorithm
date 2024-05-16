#include<stdio.h>
#include<stdlib.h>
#define size 20
struct hash{
    int data;
    struct hash *next;
}*hashtable[size];
void insert(int data){
    int index=data%size;
    struct hash *newnode=(struct hash *)malloc(sizeof(struct hash));
    newnode->data=data;
    newnode->next=NULL;
    if(hashtable[index]==NULL){
        hashtable[index]=newnode;
    }
    else{
        struct hash *temp=hashtable[index];
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
int search(int data){
    int index=data%size;
    struct hash *temp=hashtable[index];
    while(temp!=NULL){
        if(temp->data==data){
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}
void main(){
    for(int i=0;i<size;i++){
        hashtable[i]=NULL;
    }
    int data,choice,ch=1;
    while(ch){
        printf("1.Insert\n2.Search\n3.Exit\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("Enter a number to insert in the hash table:");
                   scanf("%d",&data);
                   insert(data);
                   break;
            case 2:printf("Enter a number to search:");
                   scanf("%d",&data);
                   if(search(data)){
                       printf("%d is in the hash table\n",data);
                   }
                   else{
                       printf("%d is not in the hash table\n",data);
                   }
                   break;
            case 3:exit(0);
        }
        printf("Do you want to continue(1/0):");
        scanf("%d",&ch);
    }
}