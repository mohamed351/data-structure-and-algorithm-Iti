#include "LinkedListRev.h"
#include<conio.h>
int main()
{
	
	AddNode(20);
	AddNode(40);
	AddNode(60);
	AddNode(70);
	AddNode(90);
	
	Display();
	ReverseIT();
	printf("%d", GetCount());
	
	printf("\n==============================\n");
	Display();
	_getch();

	
	return 0;
}
