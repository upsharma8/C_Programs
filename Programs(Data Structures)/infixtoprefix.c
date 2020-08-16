#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>

int stack[20];
int top=-1;
void push(int a)
{
    stack[++top]=a;
}
char pop()
{
    return(stack[top--]);
}
int priority(char a)
{
    
    if(stack[top]=='$'&&(a=='/'||a=='*'||a=='-'||a=='+'))
    {
        return 1;
    }
    else if(stack[top]=='*'&&(a=='-'||a=='+'))
    {
        return 1;
    }
    else if(stack[top]=='/'&&(a=='+'||a=='-'))
    {
        return 1;
    }
    else return 0;
    
}

void main()
{
    
    int i,t,k=0;
    char a[20],p[20];
    printf("Enter expression:");
    scanf("%s",a);
    
    for(i=strlen(a)-1;i>=0;i--)
    {
        if(isalnum(a[i]))
        {
            
            p[k++]=a[i];
            
        }
        
        else if(a[i]==')')
        {
           push(a[i]);    
        }
        else if(a[i]=='(')
        {
            while(stack[top]!=')')
            {
                
                
                p[k++]=pop();
                
            
            }
            pop();
        }    
        
        else 
        {
            while( priority(a[i]))
            {
                p[k++]=pop();
                
            }
            push(a[i]);
            
        }
    }    
      
        while(top>=0)
        {
            
            p[k++]=pop();
        }
        while(k>=0)
        {
            printf("%c",p[k--]);
        }
              
getch();

        
        
}    











