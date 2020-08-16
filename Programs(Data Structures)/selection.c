
#include<stdio.h>
#include<conio.h>
#define MAX 30
void selectionsort(int *a,int n)
{
  int j,k,temp,min;
  for(k=0;k<n-1;k++)
  {
  	min=k;
  	for(j=k+1;j<n;j++)
  	{
        
      if(a[j]<a[min]) 
   	  {
	   min=j;
     }  
  		
    }
    temp=a[min];
	   a[min]=a[k];
	   a[k]=temp;	
  }	
}

void main()
{
	
	int i,n,a[MAX];
	printf("Enter size of array");
	scanf("%d",&n);
	printf("Enter elemets of arry");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	selectionsort(a,n);
   for(i=0;i<n;i++)
   {
   	printf("%d ",a[i]);
	   }	
	getch();
}


