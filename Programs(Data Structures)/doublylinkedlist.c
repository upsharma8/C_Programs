#include<stdio.h>  
#include<stdlib.h>  
struct node  
{  
    struct node *prev;  
    struct node *next;  
    int data;  
};  
struct node *head=NULL;
struct node *tail=NULL;
void insertion_beginning();  
void insertion_last();
void insertion_after();
void insertion_before();
void insertion_specified();  
void deletion_beginning();  
void deletion_last();  
void deletion_after();
void deletion_before();
void display();  

void main ()  
{  
int choice =0;  
    while(1)  
    {  
        printf("\n*********Main Menu*********\n");  
        printf("\nChoose one option from the following list ...\n");  
        printf("\n===============================================\n");  
        printf("\n1.Insert in begining\n2.Insert at last\n3.Insert after\n4.INsert before\n5.Delete from Beginning\n 6.Delete from last \n7.Delete after\n8.Delete before\n9.Display\n10.Exit \n");  
        printf("\nEnter your choice?\n");  
        scanf("\n%d",&choice);  
        switch(choice)  
        {  
            case 1: insertion_beginning();  
                    break;  
            case 2: insertion_last();  
                    break;  
            case 3: insertion_after();  
                    break;  
            case 4: insertion_before();
                    break;
            case 5: deletion_beginning();  
                    break;  
            case 6: deletion_last();  
                    break;  
            case 7: deletion_after();  
                    break;  
            case 8: deletion_before();
                    break;
            case 9: display();  
                    break;  
            case 10:exit(0);  
            break;  
            default:  
            printf("Please enter valid choice..");  
        }  
    }  
}  
void insertion_beginning()  
{  
   struct node *ptr;   
   int item;  
   ptr = (struct node *)malloc(sizeof(struct node));  
   if(ptr == NULL)  
   {  
       printf("\nOVERFLOW");  
   }  
   else  
   {  
    printf("\nEnter Item value");  
    scanf("%d",&item);  
      
   if(head==NULL)  
   {  
       ptr->next = NULL;  
       ptr->prev=NULL;  
       ptr->data=item;  
       head=tail=ptr;  
   }  
   else   
   {  
       ptr->data=item;  
       ptr->prev=NULL;  
       ptr->next = head;  
       head->prev=ptr;  
       head=ptr;  
   }  
   printf("\nNode inserted\n");  
}  
     
}  
void insertion_last()  
{  
   struct node *ptr;  
   int item;  
   ptr = (struct node *) malloc(sizeof(struct node));  
   if(ptr == NULL)  
   {  
       printf("\nOVERFLOW");  
   }  
   else  
   {  
       printf("\nEnter value");  
       scanf("%d",&item);  
        ptr->data=item;  
       if(head == NULL)  
       {  
           ptr->next = NULL;  
           ptr->prev = NULL;  
           head = tail=ptr;  
       }  
       else  
       {  
         
          
          tail->next = ptr;  
          ptr ->prev=tail;  
          ptr->next = NULL; 
          tail=ptr;
          }  
             
       }  
     printf("\nnode inserted\n");  
    }  
  
void insertion_after()
{
    struct node *ptr,*loc,*temp;  
   int item,x;
      ptr = (struct node *) malloc(sizeof(struct node));  
   temp=head;
   printf("Enter element after which to insert");
   scanf("%d",&x);
   while(temp!=NULL&& temp->data!=x)  
   {
       
     temp=temp->next;  
   }
   loc=temp;
   if(loc==NULL)
   {
       printf("No elemt found");
       return;
   }
   else  
   {  
       printf("\nEnter value");  
       scanf("%d",&item);  
        ptr->data=item; 
       if(loc->next == NULL)  
       {  
           ptr->next = NULL;  
           loc->next=ptr;
           ptr->prev = loc;  
           tail=ptr;  
       }  
       else  
       { 
           
          ptr ->prev=loc;  
          ptr->next = loc->next;
          (loc->next)->prev=ptr;
          loc->next=ptr;
          
        }  
             
      }  
     printf("\nnode inserted\n");  
}

void insertion_before()
{
    struct node *ptr,*loc,*temp;  
   int item,x;
      ptr = (struct node *) malloc(sizeof(struct node));  
   temp=head;
   printf("Enter element before which to insert");
   scanf("%d",&x);
   while(temp!=NULL&& temp->data!=x)  
   {
       
     temp=temp->next;  
   }
   loc=temp;
   if(loc==NULL)
   {
       printf("No elemt found");
       return;
   }
   else  
   {  
       printf("\nEnter value");  
       scanf("%d",&item);  
        ptr->data=item; 
       if(loc->prev == NULL)  
       {  
           ptr->prev = NULL;  
           loc->prev=ptr;
           ptr->next= loc;  
           head=ptr;  
       }  
       else  
       { 
           
          ptr ->prev=loc->prev;  
          ptr->next = loc;
          (loc->prev)->next=ptr;
          loc->prev=ptr;
          
        }  
             
      }  
     printf("\nnode inserted\n");  
}

void deletion_beginning()  
{  
    struct node *ptr;  
    if(head == NULL)  
    {  
        printf("\n UNDERFLOW");  
    }  
    else
    {
        ptr=head;
    if(head==tail)  
    {  
        head=tail= NULL;   
          
    }  
    else  
    {  
        (ptr->next)->prev=NULL;
        
        head = ptr->next;  
          
    }     
    free(ptr);  
    printf("\nnode deleted\n"); 
    }
}  

void deletion_last()  
{  
    struct node *ptr;  
    if(head == NULL)  
    {  
        printf("\n UNDERFLOW");  
    }  
    else 
    {
        ptr=tail;
    if(head==tail)  
    {  
        head =tail= NULL;   
           }  
    else   
    {  
       (ptr->prev)->next=NULL;
       tail=ptr->prev;
    }  
     free(head);   
        printf("\nnode deleted\n"); 
    }        
}  
void deletion_after()
{
    struct node *ptr,*loc,*temp;  
   int item,x;
      ptr = (struct node *) malloc(sizeof(struct node));  
   temp=head;
   printf("Enter element after which to delete");
   scanf("%d",&x);
   while(temp!=NULL&& temp->data!=x)  
   {
       
     temp=temp->next;  
   }
   loc=temp;
   if(loc==NULL||loc->next==NULL)
   {
       printf("No elemt found");
       return;
   }
   else  
   {  
       if((loc->next)->next==NULL)
        {
            ptr=loc->next;
            loc->next=NULL;
            tail=loc;
            free(ptr);
        }
        else{
            ptr=loc->next;
            loc->next=ptr->next;
            (ptr->next)->prev=loc;
            free(ptr);
      }
            printf("ELement deleted\n");
      }            
}
void deletion_before()
{
    struct node *ptr,*loc,*temp;  
   int item,x;
      ptr = (struct node *) malloc(sizeof(struct node));  
   temp=head;
   printf("Enter element before which to delete");
   scanf("%d",&x);
   while(temp!=NULL&& temp->data!=x)  
   {
       
     temp=temp->next;  
   }
   loc=temp;
   if(loc==NULL||loc->prev==NULL)
   {
       printf("No elemt found");
       return;
   }
   else  
   {  
       if((loc->prev)->prev==NULL)
        {
            ptr=loc->prev;
            loc->prev=NULL;
            head=loc;
            free(ptr);
        }
        else{
            ptr=loc->prev;
            loc->prev=ptr->prev;
            (ptr->prev)->next=loc;
            free(ptr);
          
        }
            printf("ELement deleted\n");
            
   }            
}


void display()
{
    struct node* temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
}



