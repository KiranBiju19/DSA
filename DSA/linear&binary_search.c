#include<stdio.h>
int n,key,l,m,h,flag=0,i;
int a[100];
void ls()
{
  printf("Enter the element to search");
  scanf("%d",&key);
  for(i=0;i<n;i++)
  {
    if(a[i]==key)
       {
         flag=1;
         break;
       }
  } 
  if(flag==1)
    printf("Element discovered at position %d",i+1);
  else
    printf("Element not found");
}

void bs()
{
    printf("\nEnter the element to search: ");
  scanf("%d",&key);
  l=0;
  h=n-1;
  while(l<=h)
  {
   m=(l+h)/2;
   if(a[m]==key)
     {
     flag=1;
     break;
     }
   else if(key>m)
     l=m+1;
   else 
     h=m-1;
  }
  if (flag==1)
    printf("Element found at postion %d\n",m);
  else
    printf("Element not found\n");
}

int main()
{
  int ch;
  printf("Enter the array size ");
  scanf("%d",&n);
  printf("Enter the elements");
  for(i=0;i<n;i++)
     scanf("%d",&a[i]);
  do{
      printf("**MENU**\n1.Linear Search\n2.Binary Search\n");
      scanf("%d",&ch);
      switch(ch)
      {
          case 1: ls(); break;
          case 2: bs(); break;
      }
  }while(ch!=0);
}