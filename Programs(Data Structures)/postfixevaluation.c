#include<stdio.h>
#include<string.h>
#include<ctype.h>

int stack[20];
int top=-1;
void push(int a)
{
    stack[++top]=a;
}
int pop()
{
    return(stack[top--]);
}

void main()
{
    int i,x,y,res;
    char a[20];
    printf("Enter expression:");
    scanf("%s",a);
    
    for(i=0;i<strlen(a);i++)
    {
        if(isdigit(a[i]))
        {
            push(a[i]-'0');
        }
        
        else
        {
             x=pop();
             y=pop();
             switch(a[i])
             {
             case '+':   res=x+y;
                          break;
              case '-':   res=y-x;
                          break;
              case '*':   res=x*y;
                          break;
              case '/':   res=y/x;              
                 
             }
             
             push(res);
        }
  
    }
    printf("REsult is %d",stack[top]);
getch();
    
}


