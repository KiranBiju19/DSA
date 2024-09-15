#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *lchild;
  struct node *rchild;
  struct node *parent;
};

int v;
struct node *start=NULL;
struct node *x;
struct node *y;
struct node *z;
struct node *temp;
struct node *r;


void insert()
{
   printf("\nEnter the element:\t");
   scanf("%d",&v);
   struct node *nn=(struct node*)malloc(sizeof(struct node));
   nn->data=v;
   nn->lchild=NULL;
   nn->rchild=NULL;
   nn->parent=NULL;
   x=start;
   y=NULL;
   if(start==NULL)
     start=nn;
   else
   {
     while(x!=NULL)
     { 
       y=x;
       if(nn->data < x->data)
          x=x->lchild;
       else
         x=x->rchild;
     }
     nn->parent=y;
     if(nn->data < y->data)
      y->lchild=nn;
     else
      y->rchild=nn;
      if(y==NULL)
      {
        start=nn;
        return;
      }
   }
}


void display(struct node* root)
{
  if(root!=NULL)
  {
    display(root->lchild);
    printf("%d\t",root->data);
    display(root->rchild);
  }
}

void find(struct node *temp,int v)
{
  if(temp!=NULL)
   {
     if(temp->data==v)
          {
            r=temp;
            return;
          }
      find(temp->rchild,v);
      find(temp->lchild,v);
    }
}


struct node *insuc(struct node *temp1)
{
  
  if(temp1->lchild==NULL)
  {
    return temp1;
  }
  insuc(temp1->lchild);
}

void delete(struct node* start,struct node *z)
{
  if(z->lchild==NULL || z->rchild==NULL)
     y=z;
   else
   {
     temp=z;
     y=insuc(temp->rchild);
   }
   if(y->lchild!=NULL)
     x=y->lchild;
   else
     x=y->rchild;
   if (x!=NULL)
     x->parent=y->parent;
   if(y->parent==NULL)
     { 
       start=x;
       return;
     }
   if(y==y->parent->lchild)
      y->parent->lchild=x;
   else
     y->parent->rchild=x;
   if(y!=z)
     {
       int tt=y->data;
       y->data=z->data;
       z->data=tt;
      }
     printf("Deletion completed\n\tDeleted node is %d",y->data);
     free(y);
}


int main()
{
  int h;
  do 
  {
    printf("\n****MENU****\n\t1.Insert\n\t2.Delete\n\t3.Display\n\t0.Exit\n");
    scanf("%d",&h);
    switch (h)
    {
      case 1: insert(); break;
      case 2: if(start==NULL)
                {
                    printf("\nEMPTY...\n");
                    break;
                }
              printf("\nEnter the number to be deleted:\t");
              scanf("%d",&v);
              temp=start;
              find(temp,v);
              delete(start,r); 
              break;
      case 0: break;
      case 3: if(start==NULL)
                {
                    printf("\nEMPTY...\n");
                    break;
                }
              display(start); 
              break;
      default: printf("WRONG CHOICHE....");
    }
  }while(h!=0);
}