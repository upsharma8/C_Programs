
#include<stdio.h>
#include<conio.h>
#define MAX 30
void shellsort(int *a,int n)
{
  int d,temp,i;
  d=n/2;
  while(d>=1)
  {
  	for(i=0;i<n-d;i++)
     {
     	if(a[i]>a[i+d])
     	{
0     		temp=a[i];
     		a[i]=a[i+d];
     		a[i+d]=temp;
		 }
	 }
	 if(d==1)
	 return;
	 d=d/2.0+0.5;
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
	shellsort(a,n);
   for(i=0;i<n;i++)
   {
    	printf("%d ",a[i]);
   }	
	getch();
}


