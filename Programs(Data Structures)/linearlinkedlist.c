#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
    int info;
    struct node *next; 
};
struct node *head=NULL;

void insertatbeg()
{
    struct node* p;
    p=(struct node*)malloc(sizeof(struct node));
        int x;
        printf("Enter element");
        scanf("%d",&x);
        p->info=x;
        if(head==NULL)
        {
        	p->next=NULL;
		}
		else
		{
	    
        p->next=head;
		
		    
		}
        head=p;
       
    
}
void insertatend()
{
   struct node *p,*temp;
    p=(struct node*)malloc(sizeof(struct node));
    
        int x;
        printf("Enter element");
         scanf("%d",&x);
       p->info=x;
       p->next=NULL;
       if(head==NULL)
       {
           head=p;
           
       }
       else
       { 
        temp=head;
        while(temp->next!=NULL)
        {
           
           temp=temp->next;
           
       }
       
        temp->next=p;
       }
        
}

void insertafter()
{
     struct node *p,*temp,*loc;
    p=(struct node*)malloc(sizeof(struct node));
       
        int x,y;
        printf("\nEnter the element to insert");
        scanf("%d",&y);
        printf("eneter element after which to insert:");
        scanf("%d",&x);
        temp=head;
        while(temp!=NULL && temp->info!=x)
        {
            temp=temp->next;
        }
        loc=temp;
        if(loc==NULL)
        {
            printf("Element not found");
        }
        
        else
        {
            p->info=y;
            p->next=loc->next;
            loc->next=p;
        }
       
}

void inserbefore()
{
     struct node *p,*temp,*q;
    p=(struct node*)malloc(sizeof(struct node));
       
        int x,y;
        printf("\nEnter the element to insert");
        scanf("%d",&y);
        printf("eneter element before which to insert:");
        scanf("%d",&x);
        p->info=y;
        
       if(head==NULL)
        {
            printf("Element not found");
        }
        else
        {
           temp=head;	
           while(temp!=NULL && temp->info!=x)
          {
            q=temp;
            temp=temp->next;
          }
        
        
          if(temp->info==x)
          {
            if(temp==head)
            {
                p->next=temp;
                head=p;
            }
        
           else
           {
             p->next=temp;
             q->next=p;
           }
         }
       }  
   
        if(temp==NULL)
        {
           printf("NOde Not Found");
        }
      
}

void deleteatbeg()
{
    struct node *p;
    int x;
    if(head==NULL)
    {
        printf("Underflow");
    }
    else
    {
        x=head->info;
        p=head;
        head=p->next;
        free(p);
    printf("Deleted element is %d",x);
        
    }
    
}

void deleteafter()
{
	int x;
    struct node *p,*temp,*loc;
    printf("Enter  elemt after whic to delete:");
    scanf("%d",&x);
    temp=head;
   while(temp!=NULL && temp->info!=x)
   {
       temp=temp->next;
   }
   loc=temp;
   if(loc==NULL||loc->next==NULL)
   {
       printf("Not found");
   }
  else
  {
      p=loc->next;
      loc->next=p->next;
      free(p);
  }
    
}

void deleteatend()
{
     struct node *p,*prev;
    int x;
    if(head==NULL)
    {
        printf("Underflow");
    }
    else
    {
         
        
        if(head->next==NULL)
        {
            x=head->info;
            p=head;
            head=NULL;
            free(p);
        }
        else
        {
            
        prev=head;
        p=head->next;
        
        
        
        while(p->next!=NULL)
        {
            prev=p;
            p=p->next;
        }
        x=p->info;
        prev->next=NULL;
        free(p);
       }    
        printf("Deleted element is %d",x);
       
    
            
    }
    
    
}

void display()
{
	struct node *temp;
	if(head==NULL)
	{
	    printf("No elements to display");
	}
	else
	{
	    
	
	   temp=head;
	   printf("Elements are:");
	
	   while(temp!=NULL)
	   {
		printf("%d",temp->info);
		temp=temp->next;
	   }

	   printf("\n"); 
	}    
	
}

void reverse()
{
    struct node *cur,*prev,*nnext;
    cur=head;
    prev=NULL;
    nnext=cur->next;
    cur->next=NULL;
    while(nnext!=NULL)
    {
        prev=cur;
        cur=nnext;
        nnext=cur->next;
        cur->next=prev;
    }
    head=cur;
    
}

void main()

{
    
    int choice;
   while(1){
       
    printf("\n1 for insert at beginning\n");
    printf("2 for innserting at end\n");
    printf("3 fron insert at after\n");
    printf("4 for insert at before\n ");
    printf("5 for delete from beginning\n");
    printf("6 for delete after a given\n");
    printf("7 for delete at end\n");
    printf("8 for reversing of linked list\n");
    printf("9 for display of linked list\n");
    printf("10 for exiting ");
	printf("Enter choice\n");
    scanf("%d",&choice);
    
    switch(choice)
    {
        
        case 1:  insertatbeg();
             
                 break; 
        case 2: insertatend();
             
                 break;  
        case 3: insertafter();
             
                 break;   
        case 4: inserbefore();
                       
                 break;           
        
        case 5: deleteatbeg();
             
                 break;  
                 
        case 6:deleteafter();
             
                 break;  
        case 7: deleteatend();
                break;
        case 8: reverse();
               break;
        case 9: display();
                break;
        
		case 10: exit(0);
                break;

       default: printf("Wrong choice");
    }
    
  
}
    
getch();    

}    



