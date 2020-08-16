#include<stdio.h>
#include<conio.h>
#define MAX 30
void bubblesort(int *a,int n)
{
  int j,k,temp;
  for(k=1;k<n;k++)
  {
  	for(j=0;j<n-k;j++)
  	{
        
     if(a[j]>a[j+1]) 
	 {
	   temp=a[j];
	   a[j]=a[j+1];
	   a[j+1]=temp;	
   	 }  
  		
    }
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
	bubblesort(a,n);
   for(i=0;i<n;i++)
   {
   	printf("%d ",a[i]);
	   }	
	getch();
}


