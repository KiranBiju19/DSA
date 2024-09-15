#include<stdio.h>
#include<stdlib.h>
#define size 100
int adjmatrix[size][size],visited[size],graph[size],queue[size];
int choice,start,edge,vertex,front=0,rear=0;
void insertedge(int from,int to)
{
    adjmatrix[from][to]=1;
    adjmatrix[to][from]=1;
}
void insertion()
{
    int from,to;
    printf("enter the no of vertices: ");
    scanf("%d",&vertex);
    printf("enter the no of edges: ");
    scanf("%d",&edge);
    for(int i=1;i<=vertex;i++)
    {
     for(int j=1;j<=edge;j++)
     {
          adjmatrix[i][j]=0;
     }
     }
    for(int i=1;i<=vertex;i++)
    {
        graph[i]=vertex;
    }
    for(int i=1;i<=edge;i++)
    {
       printf("enter the edge pairs " );
       printf("\nenter from to : ");
       scanf("%d %d",&from,&to);
       insertedge(from,to);
    }
    printf("\n Adjacent matrix\n");
    for(int i=1;i<=vertex;i++)
    {
     for(int j=1;j<=vertex;j++)
     {
          printf("%d\t",adjmatrix[i][j]);
     }
     printf("\n");
     }
}
void BFS_transversal(int start)
{    int worknode;
     for(int i=1;i<=edge;i++)
     { visited[i]=0;
     }
     queue[++rear]=start;
     front=1;
      
     while(front<=rear)
     {
         worknode=queue[front++];
         visited[worknode]=1;         
         printf("%d\t ",worknode);
         for(int i=1;i<=vertex;i++)
         {
             if(adjmatrix[worknode][i]==1&&visited[i]==0)
             {
                   queue[++rear]=i;
                   visited[i]=1;            
             }
         }
         
     }
}

void main()
{ int startedge;
  
             insertion();      
        
             printf("enter the start edge: ");
             scanf("%d",&startedge);
             BFS_transversal(startedge);
        printf("\n");
}