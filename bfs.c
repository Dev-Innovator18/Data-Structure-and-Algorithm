#include<stdio.h>
#include<stdlib.h>
#define size 100
int queue[size];
int front=-1,rear=-1;
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
}
void enqueue(int data){
    if(rear==size-1){
        printf("Queue overflow");
    }
    else{
        if(front==-1){
            front=0;
        }
        queue[++rear]=data;
    }
}
int dequeue(){
    if(rear==-1 || front>rear){
        printf("Queue underflow");
        return -1;
    }
    return queue[front++];
}
void markvisited(int node){
    visited[node]=1;
}
int isvisited(int node){
    return visited[node];
}
void bfs(struct graph *Graph,int startvertex){
    for(int i=0;i<Graph->numvertices;i++){
        visited[i]=0;
    }
    enqueue(startvertex);
    markvisited(startvertex);
    while(front <= rear){
        int curvertex=dequeue();
        printf("%d ",curvertex);
        struct node *temp=Graph->adjlist[curvertex];
        while(temp){
            if(!isvisited(temp->data)){
                enqueue(temp->data);
                markvisited(temp->data);
            }
            temp=temp->next;
        }
    }
}
void main(){
    int numvertices,numedges,source,src,dest;
    printf("Enter the number of vertices:");
    scanf("%d",&numvertices);
    printf("Enter the number of edges:");
    scanf("%d",&numedges);
    printf("Enter the start vertex:");
    scanf("%d",&source);
    struct graph *Graph=creategraph(numvertices);
    for(int i=0;i<numedges;i++){
        printf("Enter source for edge %d:",i+1);
        scanf("%d",&src);
        printf("Enter destination for edge %d:",i+1);
        scanf("%d",&dest);
        addedge(Graph,src,dest);
    }
    printf("BFS traversal from %d:\n",source);
    bfs(Graph,source);
    printf("\n");
}