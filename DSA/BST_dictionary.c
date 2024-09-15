//This is a code for creation of Binary Search Tree for Dictionary.......10/10
#include<stdlib.h>
#include<stdio.h>
#include <string.h>
struct node 
{
    char data[30];
    struct node*link;
    struct node*rchild,*lchild,*parent;
};
struct node *start=NULL;
void insert()
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the string: ");
    scanf("%s",newnode->data);
    newnode->link=NULL;
    newnode->parent=NULL;
    newnode->rchild=NULL;
    newnode->lchild=NULL;
    if(start==NULL)
    {
        start=newnode;
        return;
    }
    else
    {
        
        struct node *temp=start;
        struct node *p;
        while(temp!=NULL)
        {
          int r=strcmp(temp->data,newnode->data);
          p=temp;
          if(r<0)
           temp=temp->rchild;
          if(r>0)
           temp=temp->lchild;
          if(r==0)
            {
                printf("Word already present........");
                return;
            }
        }
        newnode->parent=p;
        int r=strcmp(p->data,newnode->data);
        if(r<0)
           p->rchild=newnode;
        else if(r>0)
           p->lchild=newnode;
        
    }
}

void display(struct node *ptr)
{
    if(ptr!=NULL)
    {
    display(ptr->lchild);
    printf("%s  ",ptr->data);
    display(ptr->rchild);
    }
}

int main()
{
    int ch;
    do{
        printf("\n\t**MENU**\n\t0.Exit\n\t1.Insert\n\t2.Display\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 0: break;
            case 1:insert(); break;
            case 2:
                   if(start==NULL)
                     printf("\nDICTIONARY IS EMPTY");
                   display(start); break;
            default:printf("\nWRONG CHOICE...");
        }
    }while(ch!=0);
}