#include<stdio.h>

int main()
{
   printf("Enter the array size: ");
   int n;
   scanf("%d",&n);
   int a[n];
   printf("Enter the elements:\n");
   int i,j;
   for(i=0;i<n;i++)
      scanf("%d",&a[i]);
   for(i=1;i<n;i++)
   {
       int temp=a[i];
       j=i-1;
       while(j>=0 && a[j]>temp)
       {
         a[j+1]=a[j];
         j--;
       }
       a[j+1]=temp;
   }
   
   printf("Sorted array is: \n");
   for(i=0;i<n;i++)
     printf("%d ",a[i]);
   
}
