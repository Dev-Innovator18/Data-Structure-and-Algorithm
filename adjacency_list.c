#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void readgraph(int n,struct node *adj[n]){
    int i,j,k,data;
    struct node *newnode,*last=NULL;
    for(i=0;i<n;i++){
        struct node *last=NULL;
        printf("How many adjacent vertices to %d:",i);
        scanf("%d",&k);
        for(j=0;j<k;j++){
            newnode=(struct node*)malloc(sizeof(struct node));
            printf("Enter the %d neighbour of %d:",j,i);
            scanf("%d",&data);
            newnode->data=data;
            newnode->next=NULL;
            if(adj[i]==NULL){
                adj[i]=newnode;
            }
            else{
                last->next=newnode;
            }
            last=newnode;
        }
    }
}
void printgraph(int n,struct node *adj[n]){
    struct node *temp;
    int i;
    for(i=0;i<n;i++){
        temp=adj[i];
        printf("The adjacent vertices to %d are:",i);
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}
void main(){
    int n,i;
    printf("Enter the number of vertices:");
    scanf("%d",&n);
    struct node *adj[n];
    for(i=0;i<n;i++){
        adj[i]=NULL;
    }
    readgraph(n,adj);
    printgraph(n,adj);
}