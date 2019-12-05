#include<stdlib.h>

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
	while (temp_fast !=NULL || temp_fast->next !=NULL)
	{
		temp_fast = temp_fast->next->next;
		temp_slow = temp_slow->next;
	}

	return temp_slow;
}
//reverse The Linked List
void ReverseIT()
{
	struct Node *temp = Tail;
	struct Node *middle = GetTheMiddle();
	while (Tail  != middle)
	{
		//1-swap between temp and tail
		temp = Tail;
		Tail = temp->prev;

		//2-sperate temp from 
		temp->prev->next = NULL;
		temp->prev = NULL;
		Head->prev = temp;
		temp->next = Head;
		Head = temp;
	}

}
