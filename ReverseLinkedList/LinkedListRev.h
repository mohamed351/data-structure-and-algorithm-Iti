#include<stdlib.h>
#include<stdio.h>
//Normal Implementation of linked list
struct Node {
	int data;
	struct Node *next;
	struct Node *prev;
};
struct Node *Head;
struct Node *Tail;
struct Node *CreateNode(int data) {
	struct Node *ptr =NULL;
	ptr = (struct Node *) malloc(sizeof(struct Node));
	if (ptr)
	{
		ptr->data = data;
		ptr->next = NULL;
		ptr->prev = NULL;

	}
	return ptr;

}
int AddNode(int data) {

	struct Node *ptr = NULL;
	int returnval = -1;
	ptr = CreateNode(data);
	if (ptr)
	{
		if (Head == NULL)
		{
			Head = Tail = ptr;
		}
		else
		{
			Tail->next = ptr;
			ptr->prev = Tail;
			Tail = ptr;
		}
		returnval = 1;
	}

	return returnval;

}
//get the address of the middle
struct Node*GetTheMiddle()
{
	struct Node * temp_slow = Head;
	struct Node  *temp_fast = Head;
	while (temp_fast !=NULL && temp_fast->next !=NULL)
	{
		temp_fast = temp_fast->next->next;
		temp_slow = temp_slow->next;
	}

	return temp_slow;
}
//reverse The Linked List
int GetCount()
{
	int count = 0;
	struct Node *temp = Head;
	while (temp)
	{

		count++;
		temp = temp->next;
	}
	return count;
}
void ReverseIT()
{
	int i;
	int counter = GetCount();
	
	
	for ( i = 0; i < counter; i++)
	{
		struct Node *tempHead = Head;


		Head = Head->next;
		tempHead->next->prev = NULL;
		tempHead->next = NULL;
		Tail->next = tempHead;
		tempHead->prev = Tail;
		Tail = tempHead;
	}

		
	
	



}



//testing of Display
void Display()
{
	struct Node * temp = Head;
	while (temp)
	{
		printf("%d \n", temp->data);
		temp = temp->next;
	}

}
