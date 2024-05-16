#include<stdio.h>
#include<stdlib.h>
#define size 100
int visited[size];
struct node{
    int data;
    struct node *next;
};
struct graph{
    int numvertices;
    struct node **adjlist;
};
struct node *createnode(int data){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}
struct graph *creategraph(int numvertices){
    struct graph *Graph=(struct graph*)malloc(sizeof(struct graph));
    Graph->numvertices=numvertices;
    Graph->adjlist=(struct node**)malloc(numvertices*(sizeof(struct node*)));
    for(int i=0;i<Graph->numvertices;i++){
        Graph->adjlist[i]=NULL;
    }
    return Graph;
}
void addedge(struct graph *Graph,int src,int dest){
    struct node *temp=createnode(dest);
    temp->next=Graph->adjlist[src];
    Graph->adjlist[src]=temp;
    temp=createnode(src);
    temp->next=Graph->adjlist[dest];
    Graph->adjlist[dest]=temp;
}void markvisited(int node){
    visited[node]=1;
}
int isvisited(int node){
    return visited[node];
}
void dfs(struct graph *Graph,int startvertex){
    markvisited(startvertex);
    printf("%d ",startvertex);
    struct node *temp=Graph->adjlist[startvertex];
    while(temp){
        if(!isvisited(temp->data)){
            dfs(Graph,temp->data);
        }
        temp=temp->next;
    }
}
void beforedfs(struct graph *Graph,int startvertex){
    for(int i=0;i<Graph->numvertices;i++){
        visited[i]=0;
    }
    dfs(Graph,startvertex);
}
void main(){
    int numvertices,numedges,source,src,dest;
    printf("Enter the number of vertices:");
    scanf("%d",&numvertices);
    printf("Enter the number of edges:");
    scanf("%d",&numedges);
    struct graph *Graph=creategraph(numvertices);
    for(int i=0;i<numedges;i++){
        printf("Enter source for edge %d:",i+1);
        scanf("%d",&src);
        printf("Enter destination for edge %d:",i+1);
        scanf("%d",&dest);
        addedge(Graph,src,dest);
    }
    printf("Enter the start vertex:");
    scanf("%d",&source);
    printf("DFS traversal from %d:\n",source);
    beforedfs(Graph,source);
    printf("\n");
}