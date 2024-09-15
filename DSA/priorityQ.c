#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  int pri;
  struct node *link;
};
struct node *start=NULL;

void eq()
{
  int v,p;
  struct node *nn=(struct node*)malloc(sizeof(struct node));
  printf("Enter the element and it's priority:\t");
  scanf("%d%d",&v,&p);
  nn->data=v;
  nn->pri=p;
  nn->link=NULL;
  
  struct node *temp=start;
    
    
  if(start==NULL || start->pri<=p)
     {
       nn->link=start;
       start=nn;
     }
   else
    {
      temp=start;
      while(temp->link!=NULL && temp->link->pri >= p)
        temp=temp->link;
      nn->link=temp->link;
      temp->link=nn;
    }
}

void dq()
{
  struct node *temp=(struct node*)malloc(sizeof(struct node));
  struct node *q;
  temp=start;
  if(start== NULL)
   { 
     printf("\nQueue underflow\n");
     return;
   }
  int o;
  do{
      printf("\n1.Ascending priority\n2.Descending priority\n0.Exit\n");
      scanf("%d",&o);
      int t=0,tp=100;;
      switch(o)
      {
        case 1: 
                while(temp->link != NULL)
                {
                  q=temp;
                  temp=temp->link;
                }
                printf("Deleted element is:\t%d",temp->data);
                free(temp);
                q->link=NULL;
                return;
                    
        case 2: start=start->link;
                printf("Deleted element is:\t%d",temp->data);
                free(temp);
                return;
                  
        
        case 0:break;
      }
  
  }while(o!=0);
}

void display()
{
  if(start==NULL)
   {
     printf("\nEmpty\n");
     return;
   }
   struct node *temp=start;
   while(temp!=NULL)
   {
    if(temp->pri!=0)
    printf("%d(%d)\t",temp->data,temp->pri);
    temp=temp->link;
   }
}

int main()
{
  int h;
  do 
  {
    printf("\n****MENU****\n1.Enqueue\n2.Dequeue\n3.Display\n0.Exit\n");
    scanf("%d",&h);
    switch (h)
    {
      case 1: eq(); break;
      case 2: dq(); break;
      case 0: break;
      case 3: display(); break;
    }
  }while(h!=0);
}