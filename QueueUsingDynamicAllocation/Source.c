#define  _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include"QueueHeader.h"


int main()
{
	struct Queue qu;
	int i = 0;
	int tempData = 0;
	printf("Please Enter the size of Queue : ");
	scanf("%d", &qu.size);
	qu.Data = (int *)malloc(sizeof(int)*qu.size);
	qu.Front = qu.Rear = -1;

	for (i = 0; i < qu.size; i++)
	{
		printf("==========================\n");
		printf("please Enter The Number %d : ", i + 1);
		scanf("%d", &tempData);
		Enqueue(&qu, tempData);
		printf("==========================\n");
		
	}

    
	printf("%d",Dequeue(&qu));
	
	_getch();

	

	return 0;
}