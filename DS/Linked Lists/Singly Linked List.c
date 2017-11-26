#include <stdio.h>
#include<stdlib.h>
struct NODE
{
	int INFO;
	struct NODE* LINK;//for making like [node1]->[node2]
}*START=NULL; //node type variable/pointer start
void InsertBeg(int item)
{
	struct NODE* newnode;//node type newnode
	newnode=(struct NODE*) malloc(sizeof(struct NODE));
	newnode->INFO=item;//storing the information in the info of newnode 
	if(START==NULL)//if empty we will make the link point null like [newnode]->NULL which means its the starting element
	{
		newnode->LINK=NULL;
	}
	else //if not empty
		newnode->LINK=START;//[newnode]->START 
		START=newnode;//pointer at start so that next time the element gets inserted here! (IMP)
		return;
}
//insert and end
void InsertEnd(int item)
{
	struct NODE* newnode;
	struct NODE* TEMP=NULL;
	newnode=(struct NODE*) malloc(sizeof(struct NODE));
	newnode->INFO=item;//inserts the item
	newnode->LINK=NULL;//check if it points to something (CHECKS IF THE LL IS EMPTY)
	if(START==NULL)//if it is null
	{
		START=newnode;//it is definately the first element
		return;
	}
	else//if it is not the first element
	{
		TEMP=START; 
		while(TEMP->LINK!=NULL)//till the end
			TEMP=TEMP->LINK; 
			TEMP->LINK=newnode;//temp points to the new node which is the last element in the linked list
			return;
	}
}
//insertion at any position
void InsertPos(int item,int pos)
{
	int c=1;
	struct NODE* newnode;
	newnode=(struct NODE*) malloc(sizeof(struct NODE));
	newnode->INFO=item;
	if (START==NULL && pos==1)
	{
		newnode->LINK=NULL;
		START=newnode;
		return;
	}
	else if(START==NULL&&pos>1)
	{
		printf("INVALID POSTIION\n");
		return;
	}
	else if(START!=NULL &&pos==1)
	{
		newnode->LINK=START;
		START=newnode;
		return;
	}
	struct NODE* TEMP=START;
	while(TEMP!=NULL && c!=(pos-1)) //to move temp till the position we require
	{
		TEMP=TEMP->LINK;
		c++;
	}
	if(TEMP==NULL)
	{
		printf("Invalid position\n");
		return;
	}
	newnode->LINK=TEMP->LINK;
	TEMP->LINK=newnode;
}
//delete from begining
void DeleteBegining()
{
	struct NODE* TEMP=NULL;
	if(START==NULL)
	{
		printf("SLL IS EMPTY \n");
		return;
	}
	else
	{
		TEMP=START;
		printf("%d",START->INFO);
		START=START->LINK;
		free(TEMP);
		return;
	}
}
//deleting from end
void DeleteEnd()
{
	struct NODE* temp1;
	struct NODE* temp2=NULL;
	if (START==NULL)
	{
		printf("Linked List is Empty");
		return;
	}
	else if(START->LINK==NULL)
	{
		free(START);
		START=NULL;
		return;
	}
	else
	{
		temp1=START;
		while(temp1->LINK!=NULL)
		{
			temp2=temp1;
			temp1=temp1->LINK;
		}	
		temp2->LINK=NULL;
		printf("%d\n",temp1->INFO );
		free(temp1);          
		return;
	}
}

void delete_pos(int pos)
  { struct NODE* TEMP1;
  	struct NODE* TEMP2;
    TEMP1=START;
    if(START==NULL)
		printf("SLL is Empty\n");
	    TEMP2=NULL;
    for(int k=1;k<pos;k++)
    {
      TEMP2=TEMP1;
      TEMP1=TEMP1->LINK;
    }
    TEMP2->LINK=TEMP1->LINK;
    free(TEMP1);
  }
void display()
{
	struct NODE* TEMP=NULL;
	if(START==NULL)
	{
		printf("SLL IS EMPTY\n");
		return;
	}
	else
	{
		TEMP=START;
		while(TEMP!=NULL)
		{
			printf("%d\n",TEMP->INFO );
			TEMP=TEMP->LINK;
		}
	return;	
}
}


int main()
{
	int ch,x,pos;
	while(ch!=8)
	{
		printf("enter choice \n 1 for insertion at begining \n 2 for insertion at any position \n 3 for display \n 4 for insertion at end \n 5 delete from begining \n6 for deleting from end \n 7 for deleting from position");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				{printf("Enter the value\n");
				scanf("%d",&x);
				InsertBeg(x);
				break;}
			
			case 2:
				{printf("Enter position and element");
				scanf("%d %d",&pos,&x);
				InsertPos(x,pos);
				break;}
			
			case 3:
				{printf("THe link list is\n");
				display();
				break;}
			
			case 4:
				{printf("Enter the element\n");
				scanf("%d",&x);
				InsertEnd(x);
				break;}
			
			case 5:
				{DeleteBegining();
				break;}
			case 6:
				DeleteEnd();
				break;
			case 7:
				printf("Enter the position\n");
				scanf("%d",&pos);
				delete_pos(pos);

		}
	}
}
	
