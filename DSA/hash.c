//This is code for hashing using open chaining......10/10
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*link;
};
struct node *a[100]={NULL};
int n;
struct node *create(int data)
{
    struct node *nn=(struct node*)malloc(sizeof(struct node));
    nn->data=data;
    nn->link=NULL;
    return nn;
}
void insert()
{
    printf("\nEnter the number: ");
    int data;
    scanf("%d",&data);
    struct node *nn=create(data);
    int hash=data%n;
    if(a[hash]==NULL)
    {
        a[hash]=nn;
    }
    else
    {
        nn->link=a[hash];
        a[hash]=nn;
    }
}

void display()
{
    for(int i=0;i<n;i++)
    {
        printf("[%d]",i);
        if(a[i]!=NULL)
        {
            struct node*temp=a[i];
            while(temp!=NULL)
            {
                printf("-->%d",temp->data);
                temp=temp->link;
            }
        }
        printf("\n");
    }
}
void search()
{
    int hash,s,i=0;
    printf("\nEnter the number to search: ");
    scanf("%d",&s);
    hash=s%n;
    struct node *temp=a[hash];
    while(temp->link!=NULL)
    {
     i++;
     if(temp->data==s)
     {
       printf("\nElement found at position %d of array index %d",i,hash);
       return ;
     }
    }
    printf("\nElemnt not found....");
}
int main()
{
    printf("\nEnter the Size of array: ");
    scanf("%d",&n);
    int ch;
    do
    {
        printf("\n\tMENU\n\t1.Insert\n\t2.Display\n\t3.Search\n\t");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: insert(); break;
            case 2: display(); break;
            case 3: search(); break;
            case 0: break;
            default : printf("\nWrong choice...");
        }
    }while(ch!=0);
}