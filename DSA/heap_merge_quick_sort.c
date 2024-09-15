#include<stdio.h>
int n,l,r;
int a[100];

void display(int n)      //display function for all sorts
{
  printf("\nSorted Elements:");
  for(int i=0;i<n;i++)
    printf("%d ",a[i]);
}  
void insert()
{
    printf("Enter the size of array :");
    scanf("%d",&n);
    
    printf("Start entering the elements :\n");
    for(int k=0;k<n;k++)
      scanf("%d",&a[k]);
    
}

void heap(int a[],int n,int i)          //Heap sort starting
{
 int largest=i,left=(2*i)+1,right=(2*i)+2;
 if(left<n && a[left]>a[largest])
    largest=left;
 if(right<n && a[right]>a[largest])
    largest=right;
 if(largest!=i)
   {
     int temp=a[i];
     a[i]=a[largest];
     a[largest]=temp;
     
     heap(a,n,largest);
   }
}
void bH(int a[],int n)
{
  for(int i=(n/2)-1;i>=0;i--)
   heap(a,n,i);
}
void hS(int a[],int n)
{
  bH(a,n);
  for(int i=n-1;i>0;i--)
  {
    int temp=a[0];
    a[0]=a[i];
    a[i]=temp;
    
    heap(a,i,0);
  }
}

int hepsrt()
{
  hS(a,n);
  display(n);
  printf("\n");
  return 0;
}                                         //Heap sort ending

void mG(int a[],int l,int m,int r)         //Merge sort starting
{
  int n1=m-l+1,n2=r-m,i,k,j,L[n1],R[n2];
  for(i=0;i<n1;i++)
    L[i]=a[l+i];
  for(j=0;j<n2;j++)
    R[j]=a[m+1+j];
  i=0,j=0,k=l;
  while(i<n1 && j<n2)
  {
    if(L[i]<=R[j])
    {
      a[k]=L[i];
      i++;
    }
    else
    {
      a[k]=R[j];
      j++;
    }
    k++;
  }
  while(i<n1)
  {
    a[k]=L[i];
    i++;
    k++;
  }
  while(j<n2)
  {
    a[k]=R[j];
    j++;
    k++;
  }
}

int mS(int a[],int l,int r)
{
  int m;
  
  if(l<r)
  {
   m=(l+r)/2;
   mS(a,l,m);
   mS(a,m+1,r);
   mG(a,l,m,r);
  }
  
}


int mrgsrt()
{
  mS(a,0,n-1);
  printf("\n");
  display(n);
  printf("\n");
}                                           //Merge sort ending


int partition(int a[],int l,int r)             //quick sort starting
{
  int pivot=a[r];
  int temp;
  int i=l-1;
  for(int j=l;j<r;j++)
  {
    if(a[j]<=pivot)
     {
       i++;
       temp=a[i];
       a[i]=a[j];
       a[j]=temp;
     }
  }
  temp=a[i+1];
  a[i+1]=a[r];
  a[r]=temp;
  return i+1;
}

int qS(int a[],int l, int r)
{
  if(l<r)
  {
    int p;
    p=partition(a,l,r);
    qS(a,l,p-1);
    qS(a,p+1,r);
  }
}

int qksrt()
{
  l=0;
  r=n-1;
  qS(a,l,r);
  display(n);
}                                        // quick sort ending


int main()
{
  int ch;
  insert();
  do
  {
    printf("\n\t**Menu**\n\t1.Quick Sort\n\t2.Merge Sort\n\t3.Heap Sort\n\t0.Exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1: qksrt();break;
      case 2: mrgsrt(); break;
      case 3: hepsrt();break;
      default: printf("Wrong choice");
    }
  }while(ch!=0);
}