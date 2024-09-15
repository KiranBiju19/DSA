#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
  char data;
  struct node *lchild;
  struct node *rchild;
  //struct node *parent;
};

char e[100];
struct node *s[100];
int i,j,k,top=-1;
struct node *start;

void eval()
{
    for(i=0;i<strlen(e);i++)
    {
        if(isalnum(e[i]))
          {
          struct node *nn= (struct node*)malloc(sizeof(struct node));
          nn->data=e[i];
          nn->rchild=NULL;
          nn->lchild=NULL;
          s[++top]=nn;
          }
        else
           {
               struct node *nn= (struct node*)malloc(sizeof(struct node));
               nn->data=e[i];
               nn->rchild=s[top--];
               nn->lchild=s[top--];
               s[++top]=nn;
            }
    }
}


void display(struct node *ptr)
{
    if (ptr!=NULL)
    {
        display(ptr->lchild);
        printf("%c",ptr->data);
        display(ptr->rchild);
    }
}

int main()
{
    printf("Enter the statment:");
    scanf("%s",e);
    eval();
    display(s[top]);
}