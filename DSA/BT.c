#include<stdio.h>

int a[100],q[100];
int i,j,v,p,parent,f=-1,r=-1;

int search(int k,int z)
{
    int p;
    if( z<100 && a[z]== -1)
      return -1; 
    else if(a[z]==k)
      {
        p=z;
        return p;
      }
    else 
      p=search(k,2*z);
    if(p==-1)
      p=search(k,(2*z)+1);
  
}

void insert()
{
  printf("Enter the number:\t");
  scanf("%d",&v);
  if(a[1]== -1)
  {
    a[1]=v;
    printf("\nRoot node is %d",v);
    return;
  }
  else
    {
      int ch,l=0,i=1;
      printf("Enter the parent node:\t");
      scanf("%d",&parent);
      
      l=search(parent,i);
      
      if(l==0)
      {
        printf("parent not found");
        return;
      }
      printf("Enter the child option\n1.lchild\n2.rchild\n");
      scanf("%d",&ch);
      switch(ch)
       {
         case 1: if(a[2*l]!= -1)
                  {
                   printf("Lchild already present");
                   return;
                  }
                 a[2*l]=v;
                 printf("\nData added succesfully\n");
                 break;
         case 2: if(a[(2*l)+1]!= -1)
                  {
                   printf("Rchild already present");
                   return;
                  }
                 a[(2*l)+1]=v;
                 printf("\nData added succesfully\n");
                 break;
         default: printf("Wrong choise");
       }
    }
}

void inorder(int i)
{
  if(a[i]!= -1 && i<100)
  {
    inorder(2*i);
    printf("%d ",a[i]);
    inorder((2*i)+1);
  }
}

void preorder(int i)
{
  if(a[i]!= -1 && i<100)
  {
    printf("%d ",a[i]);
    preorder(2*i);
    preorder((2*i)+1);
  }
}

void postorder(int i)
{
  if(i<100 && a[i]!= -1)
  {
    postorder(2*i);
    postorder((2*i)+1);
    printf("%d ",a[i]);
  }
}
int dq()
{
  if(f!=-1)
   {
    int z=q[f++];
    return z;
   }
  else
   printf("Queue Underflow");
}

int eq(int los)
{
  if(r<100)
    q[r++]=los;
  else
    printf("Queue Overflow");
}

void display()
{
   printf("Inorder Sequence:\n\t");
   inorder(1);
   printf("\nPreorder Sequence:\n\t");
   preorder(1);
   printf("\nPostorder Sequence:\n\t");
   postorder(1);
   return;
}

int main()
{
  int h;
  a[0]=00;
  for(i=1;i<100;i++)
    a[i]=-1;
  do 
  {
    printf("\n****MENU****\n\t1.Insert\n\t2.Display\n\t0.Exit\n");
    scanf("%d",&h);
    switch (h)
    {
      case 1: insert(); break;
      case 2: if(a[1]==-1)
              {
                printf("\nEMPTY.....\n");
                break;
              }
              display(); 
              break;
              
      case 0: break;
      default: printf("WRONG CHOICHE....");
    }
  }while(h!=0);
}