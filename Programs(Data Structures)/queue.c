#include<stdio.h>
#include<conio.h>
#define size 10
int front=-1,rear=-1;
int q[size];
void enque(int d)
{
	if(rear==size-1)
	{
		printf("Overflow");
		
	}
	else 
	{
		if(rear==-1)
		front=0;
	
	rear++;
	q[rear]=d;
   }
}
void deque()
{
  if(front==-1)
    {
       printf("Underflow");
    }
  else if(front==rear&&front!=-1)
  {
  	printf("Deleted elemet=%d",q[front]);
	  front=rear=-1;
  }  
	else
	{
		printf("Deleted=%d ",q[front]);
		front++;
	}
}
void display()
{
	int i;
  if(rear!=-1)
  {
  		  
   for(i=front;i<=rear;i++)
    {
   	  printf("Elements are :%d",q[i]);
	} 
  }
else printf("NO elements tp display\n");
}

  		 

void main()
{
int choice,d;
do
{
printf("Press 1 for enque\n");
printf("Press 2 for deque\n");
printf("Press 3 for display\n");	
printf("Press 4 to quit\n");
printf("Enter choice");
scanf("%d",&choice);



 switch(choice)
{
 case 1: printf("Enter element to insert:") ;
         scanf("%d",&d);
  		enque(d);
	    break;
 case 2: deque();
         break;		 
 case 3: display();
         break;
  case 4:exit(0);
      break;     
 default: printf("INnvalid Elements");
 }
}
 while(choice!=4);

    getch();
}





