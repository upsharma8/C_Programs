#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *left;
    struct node *right;

};



void insertbt(struct node **tree,int element)
{

struct node *ptr,*temp, *p;
ptr=( struct node*)malloc(sizeof(struct node ));
ptr->info=element;
ptr->left=ptr->right=NULL;
if(*tree==NULL)
*tree=ptr;
else{
	p=NULL;
	temp= *tree;
	while(temp!=NULL)
	{
		p=temp;
	if(element<temp->info)
			temp=temp->left;

    else
    temp=temp->right;
    
	}
	if(element<p->info)
			p->left=ptr;
	else
	 p->right=ptr;
     	
 }
}





void inorder(struct node *t)
{
    if(t!=NULL)
    {
        inorder(t->left);
        printf("%d ",t->info);
        inorder(t->right);
    }


}
int main()
{
    int num,ch;
    struct node *tree=NULL;
    while(1)
    {
        printf("enter 1 to insert element in the list\n");
        printf("enter 2 for display\n");
        printf("enter 3 to exit\n\n");
        printf("enter your choice\n");
        scanf("%d",&ch);

       switch(ch)
    {
        case 1:printf("enter a number to insert in the tree\n");
        scanf("%d",&num);
        insertbt(&tree,num);
        break;
        case 2:

                       inorder(tree);
                       printf("\n");
        break;
        case 3:exit(0);
        break;
        case 4:printf("invalid choice\n");
    }
}
return 0;
}

