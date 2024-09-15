#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *plink, *nlink;
};

struct node *start = NULL;
struct node *temp;
struct node *q;

void ifr() 
{
    int v;
    printf("Enter the element: ");
    scanf("%d", &v);
    struct node *nn = (struct node *)malloc(sizeof(struct node));
    nn->data = v;
    nn->plink = NULL;
    nn->nlink = NULL;
    
    if (start == NULL)
        start = nn;
    else 
    {
        start->plink = nn;
        nn->nlink = start;
        start = nn;
    }
    printf("Element inserted at the rear.\n");
}

void iff() 
{
    int v;
    printf("Enter the element: ");
    scanf("%d", &v);
    struct node *nn = (struct node *)malloc(sizeof(struct node));
    nn->data = v;
    nn->plink = NULL;
    nn->nlink = NULL;
    
    if (start == NULL) 
        start = nn;
    else 
    {
        temp = start;
        while (temp->nlink != NULL) 
        {
            temp = temp->nlink;
        }
        nn->plink = temp;
        temp->nlink = nn;
    }
    printf("Element inserted at the front.\n");
}

void dff() 
    { 
    if (start == NULL) 
    {
        printf("List is empty.\n");
        return;
    }
    
    temp = start;
    if (start->nlink == NULL)   
        start = NULL;
    else 
    {
        while (temp->nlink != NULL) 
        {
            q = temp;
            temp = temp->nlink;
        }
        q->nlink = NULL;
    }
    printf("Deleted element from the front: %d\n", temp->data);
    free(temp);
}

void dfr()
    {  
    if (start == NULL) 
    {
        printf("List is empty.\n");
        return;
    }
    
    temp = start;
    if (start->nlink == NULL) 
    { 
        printf("Deleted element from the rear: %d\n", start->data);
        free(start);
        start = NULL;
    } 
    else 
    {
        start = start->nlink;
        start->plink = NULL;
        printf("Deleted element from the rear: %d\n", temp->data);
        free(temp);
    }
}

void display() 
    {
    temp = start;
    if (temp == NULL) 
    {
        printf("List is empty.\n");
        return;
    }
    
    printf("The elements of the list are: ");
    while (temp != NULL) 
    {
        printf("%d ", temp->data);
        temp = temp->nlink;
    }
    printf("\n");
}

int main() 
    {
    int ch;
    do 
    {
        printf("\n**MENU**\n1.Insert from rear\n2.Insert from front\n3.Delete from rear\n4.Delete from front\n5.Display\n0.Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) 
        {
            case 1: ifr(); break;
            case 2: iff(); break;
            case 3: dfr(); break;  
            case 4: dff(); break;  
            case 5: display(); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (ch != 0);
    
    return 0;
}
