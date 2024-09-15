#include<stdio.h>
#include<stdlib.h>

int stack[100];
int top=-1;

struct node
{
    int info;
    struct node *link;
};

struct graph{
    int TotalVertices;
    int *visited;
    struct node **adjList;
};


struct node *createNode(int vertex){
    struct node *new;
    new=malloc(sizeof(struct node));
    new->info=vertex;
    new->link=NULL;
    return new;
}

struct graph *createGraph(int vert_num){
    struct graph *G;
    G=malloc(sizeof(struct graph));
    G->TotalVertices=vert_num;
    G->visited=malloc(vert_num*sizeof(int));
    G->adjList=malloc(vert_num*sizeof(struct node *));
    for(int i=0;i<vert_num;i++)
    {
        G->visited[i]=0;
        G->adjList[i]=NULL;
    }
    return G;
}
void addEdge(struct graph *G,int src,int dest){
    struct node *new=createNode(dest);
    new->link=G->adjList[src];
    G->adjList[src]=new;
}
void dfs(struct graph *G,int source){
    struct node *trav=G->adjList[source];
    struct node *temp=trav;
    G->visited[source]=1;
    stack[++top]=source;
    printf(" %d ",stack[top--]);
    while(temp!=NULL){
        stack[++top]=temp->info;
        if(G->visited[temp->info]==0){
            dfs(G,temp->info);
        }
        temp=temp->link;
    }
}
    
void display(struct graph* graph) {
  int v;
  for (v = 0; v < graph->TotalVertices; v++) {
    struct node* temp = graph->adjList[v];
    printf("\n%d =>  ", v);
    while (temp) {
      printf("%d ", temp->info);
      temp = temp->link;
    }
    printf("\n");
  }
  printf("\n");
}
int main(){
    int num_vert;
    printf("Enter the number of vertices: ");
    scanf("%d",&num_vert);
    struct graph *G=createGraph(num_vert);
    printf("Enter you edges: ");
    int edges;
    scanf("%d",&edges);
    printf("Enter you vertices (v1 v2): ");
    for(int i=0;i<edges;i++){
        int v1,v2;
        scanf("%d %d",&v1,&v2);
        addEdge(G,v1,v2);
            }
    display(G);
    printf("Enter the source from which you want to start traversal:  ");
    int source;
    scanf("%d",&source);
    dfs(G,source);
}