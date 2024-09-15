#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *link;
};
struct node *start=NULL;
struct node *temp;
int n,r=-1,f=0;
int s[100];

void insert()
{
    struct node *nn=(struct node*)malloc(sizeof(struct node));
    int v;
    printf("Enter the number:");
    scanf("%d",&v);
    nn->data=v;
    nn->link=NULL;
    if(start==NULL)
      start=nn;
    else
    {
        nn->link=start;
        start=nn;
    }
}
void reverse()
{
    temp=start;
    while(temp!=NULL)
    {
        s[++r]=temp->data;
        temp=temp->link;
    }
    temp=start;
    while(temp!=NULL)
    {
        temp->data=s[f++];
        //printf("%d ",temp->data);
        temp=temp->link;
    }
}

void display()
{
    temp=start;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->link;
    }
}
int main()
{
    printf("Enter the number of nodes you want to enter: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
      insert();
    reverse();
    display();
}