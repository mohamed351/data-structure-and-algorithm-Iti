#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;

class Node {
public:
	int Data;
	Node *next;
	
};
class Stack
{
private:
	Node * TOS;
	
public:
	Stack() {
		
		TOS = NULL;
	}

	int Push(int data)
	{
		Node *node = new Node();
		int retval = -1;

		if (node == NULL)
		{
			cout << "Stack OverFlow ";
		}
		else {
			node->Data = data;
			node->next = TOS;
			TOS = node;
			retval = 1;
			

		}

		return retval;
	}
	int Pop() {
		int retval = -1;
		if (TOS == NULL)
		{
			cout << "The Stack is Empty";
		}
		else
		{
			Node *temp;

			retval = TOS->Data;
			temp = TOS;
			TOS = TOS->next;
			delete temp;

			
		}
		return retval;
		
	}

	
};