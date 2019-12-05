#include "Stack.h"

int main()
{
	Stack sta;
	sta.Push(10);
	sta.Push(20);
	sta.Push(40);
	sta.Push(60);
	int data = sta.Pop();
	printf("%d \n", data);
	data = sta.Pop();
	printf("%d \n", data);
	data = sta.Pop();
	printf("%d \n", data);
	data = sta.Pop();
	printf("%d \n", data);


	data = sta.Pop();
	printf("%d \n", data);


	_getch();

	
	return 0;
}