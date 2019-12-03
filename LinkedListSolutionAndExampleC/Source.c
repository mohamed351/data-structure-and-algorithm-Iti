
#include<conio.h>
//single LinkedList Node
#include "StructsAndFunctions.h"


int main()
{
	printf("==============Print A===========\n");
	AddDoubleLinkedList(900);
	AddDoubleLinkedList(200);
	AddDoubleLinkedList(60);
	AddDoubleLinkedList(40);
	AddDoubleLinkedList(100);
	AddDoubleLinkedList(90);

	//from Head to tail
	DisplayDoubleLinkedList();
	printf("==============Print Reverse===========\n");
	//from tail to head 
	DisplayDoubleLinkedListReverse();
	printf("==============Some Functions Number===========\n");

	//GetMax Number in Linked List 
	int number = GetMax();
      printf("The min is :  %d\n", number);

	  int number2 = GetMin();
	  printf("The max is  : %d\n", number2);

	  printf("The Sum is  : %d \n", Sum());

	  printf("The Count is : %d \n", GetCount());


	  printf("The Middle is :%d \n", GetTheMiddle());

	  printf("===================Insert Testing ======================== \n");
	  //testing Insert Node(int data, int loc)
	  InsertNode(5, 1);
	  InsertNode(6, 0);
	  InsertNode(3, 200);
	  DisplayDoubleLinkedList();
	  printf("===================End Insert ======================== \n");


	  SortLinkedListAsBubbleSort();
	  printf("===================Bubble Sort ======================== \n");
	  DisplayDoubleLinkedList();






	_getch();



	return 0;
}