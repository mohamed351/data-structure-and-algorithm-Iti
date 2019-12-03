#include<stdlib.h>
#include<stdio.h>

struct SingleLinkedListNode {
	int Data;
	struct SingleLinkedListNode *next;
};
struct DoubleLinkedListNode {
	int Data;
	struct DoubleLinkedListNode *next;
	struct DoubleLinkedListNode *pre;
};
struct DoubleLinkedListNode *DHead;
struct DoubleLinkedListNode *DTail;
struct DoubleLinkedListNode *CreateNode(int data)
{
	struct DoubleLinkedListNode *ptr = NULL; 
	ptr =  malloc(sizeof(struct DoubleLinkedListNode)); 
	// in boland C you should Convert it  I am using Visual Studio 2017
	if (ptr)
	{
		ptr->Data = data;
		ptr->next = NULL;
		ptr->pre = NULL;
	}
	return ptr;

}
int AddDoubleLinkedList(int data) {

	int returnVal = 0;
	struct DoubleLinkedListNode *ptr = NULL;
	ptr = CreateNode(data);
	if (ptr)
	{
		if (DHead == NULL)
		{
			DTail = DHead = ptr;
		}
		else
		{
			DTail->next = ptr;
			ptr->pre = DTail;
			DTail = ptr;
		}
	}
}
void DisplayDoubleLinkedList() {
	struct DoubleLinkedListNode *temp = DHead;
	while (temp)
	{
		printf("%d \n", temp->Data);
		temp = temp->next;
	}
}
void DisplayDoubleLinkedListReverse() {
	struct DoubleLinkedListNode *temp = DTail;
	while (temp)
	{
		printf("%d \n", temp->Data);
		temp = temp->pre;
	}
}
int GetMax()
{
	int i = -8887562;
	struct DoubleLinkedListNode *temp = DHead;
	if (temp !=NULL)
	{
		while (temp)
		{
			if (temp->Data > i)
			{
				i = temp->Data;


			}
			temp = temp->next;

		}
		
		
	}
	return i;
}
int GetMin()
{
	int i;
	struct DoubleLinkedListNode *temp = DHead;
	i = temp->Data;
	if (temp != NULL)
	{
		while (temp)
		{
			if (temp->Data < i)
			{
				i = temp->Data;


			}
			temp = temp->next;

		}


	}
	return i;
}
int Sum()
{
	int count = 0;
	struct DoubleLinkedListNode *temp = DHead;
	while (temp)
	{
		count += temp->Data;
		temp = temp->next;
	}
	return count;
}
int GetTheMiddle() {

	struct DoubleLinkedListNode *slow = DHead;
	struct DoubleLinkedListNode *fast =DHead;
	while (fast !=NULL  && fast->next !=NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

	};
	return slow->Data;
}
int GetCount()
{
	int count = 0;
	struct DoubleLinkedListNode *temp =DHead;
	while (temp)
	{
		
		count++;
		temp = temp->next;
	}
	return count;
}
void SwapBubble(struct DoubleLinkedListNode * LinkedList1, struct DoubleLinkedListNode * LinkedList2) {

	int data;
	data = LinkedList1->Data;
	LinkedList1->Data = LinkedList2->Data;
	LinkedList2->Data = data;
	
}
void SortLinkedListAsBubbleSort() {

	struct DoubleLinkedListNode *temp;
	int i;
	int count = GetCount();
   
	for (i = 0;i < count;i++)
	{
		temp = DHead;
		while (temp != NULL && temp->next != NULL)
		{
			if (temp->next->Data < temp->Data)
			{
				SwapBubble(temp->next, temp);
			}
			temp = temp->next;
		}
	}
}
int InsertNode(int data, int location)
{
	int retval = 0;
	int i;
	struct DoubleLinkedListNode *ptr = NULL;
	struct DoubleLinkedListNode * temp = NULL;
	ptr = CreateNode(data);
	if (ptr)
	{ 
		
		if (DHead == NULL)
		{
			DHead = DTail = ptr;
			retval = 1;

		}
		else
		{
			if (location == 0)
			{
				DHead->pre = ptr;
				ptr->next = DHead;
				DHead = ptr;
			}
			else //location in the middle or in The Last 
			{
				temp = DHead;
				//find The Location
				for (i = 0;i < location - 1 && temp != NULL;i++)
				{
					temp = temp->next;
				}
				if (temp == DTail || temp == NULL)
				{
					DTail->next = ptr;
					ptr->pre = DTail;
					DTail = ptr;
				}
				else
				{
					temp->next->pre = ptr;
					ptr->next = temp->next;
					ptr->pre = temp;
					temp->next = ptr;


				}


			}
			retval = 1;

		}
	}
	return retval;
	
	
}

