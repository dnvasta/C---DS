#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};
struct Node* head;		//can be accessed from anywhere

void InsertBeg(int x);
void InsertEnd(int x);
void Search(int val);
void Delete(int pos);
void InsertN(int pos, int val);
void Reverse();
void Print();

int main()
{
	int i,n,x,choice,val,pos;
	head=NULL;
	while(1)
	{
		printf("Select a Choice:\n");
		printf("1) Create a list\n");
		printf("2) Insert at beginning\n");
		printf("3) Insert at End\n");
		printf("4) Search\n");
		printf("5) Delete a node\n");
		printf("6) Insert at nth node\n");
		printf("7) Reverse the list\n");
		printf("8) Display list\n");
		printf("9) Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: 
				printf("How many numbers?? \n");
				scanf("%d",&n);
				for(i=0;i<n;i++)
				{
					printf("Enter a number:\n");
					scanf("%d",&x);
					InsertBeg(x);
					Print();
				}
				break;
			
			case 2: 
				printf("Enter a number to be inserted at beginning:\n");
				scanf("%d",&x);
				InsertBeg(x);
				Print();
				break;
			
			case 3:
				printf("Enter a number to be inserted at end:\n");
				scanf("%d",&x);
				InsertEnd(x);
				Print();
				break;
			
			case 4:
				printf("Enter the number to be searched:\n");
				scanf("%d",&val);
				Search(val);
				break;
				
			case 5: 
				printf("Enter the position of node to be deleted:\n");
				scanf("%d",&pos);
				Delete(pos);
				Print();
				break;
		
			case 6:
				printf("Enter the position of node to be inserted:\n");
				scanf("%d",&pos);
				printf("Enter the number/item to be inserted: \n");
				scanf("%d",&val);
				InsertN(pos,val);
				Print();
				break;
			
			case 7:
				Reverse();
				Print();
				break;
					
			case 8:
				Print();
				break;
			
			case 9:
				exit(0);
			
			default: 
				break;
		}
	}
}

void InsertBeg(int x)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data=x;
	temp->next=head;
	head=temp;
	return;
}

void Print()
{
	struct Node* temp;
	temp=head;
	printf("\n\nList is: ");
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n\n");
	return;
}

void InsertEnd(int x)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data=x;
	struct Node* temp2;
	temp2=head;
	while(temp2->next!=NULL)
	{
		temp2=temp2->next;
	}
	temp->next=temp2->next;
	temp2->next=temp;
	return;
}

void Search(int val)
{
	int count=1;
	struct Node* temp;
	temp=head;
	while(temp!=NULL)
	{
		if(temp->data==val)
		{
			printf("Item/Number %d is found at %d\n",val,count);
			return;
		}
		count++;
		temp=temp->next;
	}
	printf("Item/Number %d NOT found!!!\n",val);
	return;
}

void Delete(int pos)
{
	int i;
	struct Node* temp1;
	temp1=head;
	struct Node* temp2;
	if(pos==1)
	{
		head=temp1->next;
		free(temp1);
		return;
	}
	
	for(i=0;i<pos-2;i++)
	{
		temp1=temp1->next;	//(n-1)th
	}
	temp2=temp1->next;		//nth
	temp1->next=temp2->next;	//(n+1)th
	free(temp2);
	return;
}

void InsertN(pos,val)
{
	int i;
	struct Node *temp1,*temp2;
	temp1=head;
	if(pos==1)
	{
		InsertBeg(val);
		return;
	}
	
	for(i=0;i<pos-2;i++)
	{
		temp1=temp1->next;	//(n-1)th
	}
	temp2=temp1->next;		//nth
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=val;
	temp->next=temp2;
	temp1->next=temp;
	return;
}

void Reverse()
{
	struct Node *prev,*current,*next;
	current=head;
	prev=NULL;
	while(current!=NULL)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	head=prev;
	return;
}
