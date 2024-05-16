#include"stdio.h"
#include"stdlib.h"
int no_vertices;
typedef struct node{
    int data;
    struct node *nxt;
}NODE;
void read_graph(NODE *adj[]){
    NODE *nn;
    int data,no_adjacent;
    for(int i=0;i<no_vertices;i++){
        NODE *last=NULL;
        printf("HOW MANY ADJACENT TO %d:",i);
        scanf("%d",&no_adjacent);
        for(int j=0;j<no_adjacent;j++){
            nn=(NODE*)malloc(sizeof(NODE));
            printf("ENTER THE %d NEIGHBOUR OF %d:",j,i);
            scanf("%d",&data);
            nn->data=data;
            nn->nxt=NULL;
            if(adj[i]==NULL){
                adj[i]=nn;
            }
            else{
                last->nxt=nn;
            }
            last=nn;
        }
    }
}
void print_graph(NODE *adj[]){
    NODE *tmp;
    for(int i=0;i<no_vertices;i++){
        tmp=adj[i];
        printf("THE ADJACENT VERTICES TO %d ARE:\n",i);
        while(tmp!=NULL){
            printf("%d\n",tmp->data);
            tmp=tmp->nxt;
        }
    }
    printf("\n");
}
void bfs(NODE* adj[],int visited[],int start){
    print_graph(adj);
    int queue[no_vertices],front=-1,rear=-1;
    visited[start]=1;
    if(front==-1){
        front=rear=0;
    }
    queue[rear]=start;
    printf("THE BFS TRAVERSAL FROM %d IS:\n",start);
    while(front<=rear){
        int current_node=queue[front++];
        printf("%d",current_node);
        NODE *ptr=adj[current_node];
        while(ptr!=NULL){
            int neighbour=ptr->data;
            if(visited[neighbour]==0){
                visited[neighbour]=1;
                queue[++rear]=neighbour;
            }
            ptr=ptr->nxt;
        }
    }
}
void dfs(NODE *adj[],int visited[],int start){
    visited[start]=1;
    printf("%d ",start);
    NODE *ptr=adj[start];
    while(ptr!=NULL){
        int neighbour=ptr->data;
        if(visited[neighbour]==0){
            visited[neighbour]=1;
            dfs(adj,visited,neighbour);
        }
        ptr=ptr->nxt;
    }
}
int main(){
    printf("ENTER THE NO OF VERTICES:");
    scanf("%d",&no_vertices);
    NODE *adj[no_vertices];
    int choice,start,visited[no_vertices];
    for(int i=0;i<no_vertices;i++){
        adj[i]=NULL;
    }
    while(1){
        printf("\nENTER THE CHOICE:1-ADDING,2-DISPLAYING,3-BFS,4-DFS,5-EXIT:");
        scanf("%d",&choice);
        if(choice==1){
            read_graph(adj);
        }
        if(choice==2){
            print_graph(adj);
        }
        if(choice==3){
            printf("ENTER THE STARTING POINT:");
            scanf("%d",&start);
            for(int j=0;j<no_vertices;j++)
            visited[j]=0;
            bfs(adj,visited,start);
        }
        if(choice==4){
            printf("ENTER THE STARTING POINT:");
            scanf("%d",&start);
            for(int j=0;j<no_vertices;j++)
            visited[j]=0;
            dfs(adj,visited,start);
        }
        if(choice==5){
            return -1;
        }
    }
    return 0;
}