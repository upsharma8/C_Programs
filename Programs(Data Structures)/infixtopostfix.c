#include<stdio.h>
#include<string.h>
#include<ctype.h>

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
    if(stack[top]==a)
    {
        return 1;
    }
    else if(stack[top]=='$'&&(a=='/'||a=='*'||a=='-'||a=='+'))
    {
        return 1;
    }
    else if(stack[top]=='*'&&(a=='-'||a=='+'||a=='/'))
    {
        return 1;
    }
    else if(stack[top]=='-'&&a=='+')
    {
        return 1;
    }
    else if(stack[top]=='+'&&a=='-')
    {
        return 1;
    }
    else return 0;
    
}

void main()
{
    
    int i,t;
    char a[20];
    printf("Enter expression:");
    scanf("%s",a);
    
    for(i=0;i<strlen(a);i++)
    {
        if(isalnum(a[i]))
        {
            printf("%c",a[i]);
        
            
        }
        
        else if(a[i]=='(')
        {
           push(a[i]);    
        }
        else if(a[i]==')')
        {
            while(stack[top]!='(')
            {
                
                printf("%c",pop());
                
            
            }
            pop();
        }    
        
        else 
        {
            while( priority(a[i]))
            {
                printf("%c",pop());
                
            }
            push(a[i]);
            
        }
    }    
        
        
        while(top>=0)
        {
            
            printf("%c",pop());
            
        }
        
        
getch();

        
        
}    


