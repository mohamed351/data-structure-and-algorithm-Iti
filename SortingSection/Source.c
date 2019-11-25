#define  _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<Windows.h>
#include<stdlib.h>
#include "FunctionsAndStructs.h"


int main()
{

	int i;
	int getnumber;
	int getID;
	char Name[20];
	
	printf("=============\n");
	printf("MargeSort \n");
	printf("============= \n");
	FillTestingData();
	MergeSort(0, 4);
	for (i = 0; i < 5; i++)
	{
		printf("id: %d \n", data[i].id);
		printf("grade: %d\n", data[i].grade);
		
		printf("name : %s \n", data[i].Name);
		printf("____________________\n");
		Sleep(1000);

	}
	
	
	printf("________________________________________\n");
	printf("________________________________________\n");
	printf("Press any key to ... see bubble sort");
	_getch();

	printf("BubbleSort --> Just Print \n");
	printf("=============================== \n");
	BubbleSortPrint(data, 5);
	_getch();

	do
	{
		system("cls");
		MergeSort(0, 4);
		printf("\nBinary Search:\n");
		printf("\n1- for ID : ");
		printf("\n2-for Name : ");
		printf("\n3- exit");
		getnumber = _getch();

		if (getnumber == 49)
		{
			printf("\nPlease Enter your ID :");
			scanf("%d", &getID);
		getID=binarySearch(data, 0, 4, getID);
		if (getID != -1)
		{
			PrintStudent(data[getID]);
		}
		else
		{
			printf("I can't find this Student");
		}
		_getch();
			
		}
  	else if (getnumber == 50) 
		{
			
			BubbleSort(data, 5);
			printf("\nPlease Enter your Name :");
			scanf("%s", Name);

		 getID =	binarySearchWithName(data, 0, 4, Name);
		 if (getID == -1)
		 {
			 printf("I can't find this Student");
		 }
		 else {
			 PrintStudent(data[getID]);
			 
		 }
		 _getch();
		 
		}
		

	} while (getnumber !=51);
	
	
	
	


	

	_getch();

	return 0;
}
