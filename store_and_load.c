#include"stdio.h"
#include"stdlib.h"
typedef struct node
{
    int vertex;
    struct node *link;
}NODE;
typedef struct adj
{
    int m;
    NODE *ptr;
}ADJ;
NODE *createnn(int vertex)
{
    NODE *nn=(NODE*)malloc(sizeof(NODE));
    nn->vertex=vertex;
    nn->link=NULL;
    return nn;
}
void add_edge(ADJ adj[],int u,int v)
{
    NODE *tmp=createnn(v);
    tmp->link=adj[u].ptr;
    adj[u].ptr=tmp;
}
void store_graph(ADJ adj[],int n)
{
    FILE *fptr=fopen("graph.txt","w");
    fprintf(fptr,"%d",n);
    fprintf(fptr,"\n");
    for(int i=0;i<n;i++)
    {
        fprintf(fptr,"%d ",i);
        fprintf(fptr,"%d ",adj[i].m);
        NODE *tmp=adj[i].ptr;
        while(tmp!=NULL)
        {
            fprintf(fptr,"%d ",tmp->vertex);
            tmp=tmp->link;
        }
        fprintf(fptr,"\n");
    }
    printf("stored sucessfully\n");
    fclose(fptr);
}
void load_graph(ADJ adj[])
{
	FILE *fptr=fopen("graph.txt","r");
    int n,m,u,v;
    fscanf(fptr,"%d",&n);
    for(int i=0;i<n;i++)
    {
        fscanf(fptr,"%d",&u);
        fscanf(fptr,"%d",&m);
        adj[u].m=m;
        for(int j=0;j<m;j++)
        {
            fscanf(fptr,"%d",&v);
            add_edge(adj,u,v);
        }
    }
}
void display(ADJ adj[],int n)
{
    NODE *tmp;
    for(int i=0;i<n;i++)
    {
        tmp=adj[i].ptr;
        printf("the adjacent vertex to %d: ",i);
        while(tmp!=NULL)
        {
            printf("%d\t",tmp->vertex);
            tmp=tmp->link;
        }
        printf("\n");
    }
}
int main()
{
    int n,u,m,v;
    printf("enter the no of vertices:");
    scanf("%d",&n);
    ADJ adj[n];
    for(int i=0;i<n;i++)
    {
        adj[i].ptr=NULL;
    }
    for(int i=0;i<n;i++)
    {
    	here:
        printf("enter the no of adjacent vertex to %d:",i);
        scanf("%d",&m);
        adj[i].m=m;
        if(m>n)
        {
        	goto here;
		}
        for(int j=0;j<m;j++)
        {
            printf("enter the %d element to %d:",j,i);
            scanf("%d",&v);
            add_edge(adj,i,v);
        }
    }
    display(adj,n);
    store_graph(adj,n);
    ADJ adjfile[n];
    for(int i=0;i<n;i++)
    {
        adjfile[i].ptr=NULL;
    }
    printf("after loading\n");
    load_graph(adjfile);
    display(adjfile,n);
    return 0;
}