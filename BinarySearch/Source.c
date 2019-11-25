#define  _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<conio.h>
#include<string.h>

struct Student {
	int ID;
	char Name[20];
	int grade;
};

int binarySearch(int data[], int begin, int end);
int binarySearchWithName(struct Student data[], int begin, int end, char *Name) {

	int location = -1;
	int lower = begin;
	int upper = end;
	int middle;

	if (lower <= upper)
	{

		middle = (lower + upper) / 2;
		if (data[middle].Name[0] == Name[0])
		{
			if (!strcmp(data[middle].Name, Name))
			{
				location = middle;
			}
			else
			{
				location = binarySearchWithName(data, begin, middle - 1, Name);
			}
		}
		else if (data[middle].Name[0] < Name[0])
		{
			location = binarySearchWithName(data, begin, middle - 1, Name);
		}
		else
		{
			location = binarySearchWithName(data, middle + 1, end, Name);
		}

	}
	return location;
}


int main()
{
	
	/*int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
    int x =	binarySearch(arr, 0, 9,3);
	printf("%d", arr[x]);*/

	struct Student students[5];
	struct Student student1;
	student1.ID = 1;
	student1.grade = 10;
	strcpy(student1.Name, "mohamed");
	students[0] = student1;



	struct Student student2;
	student2.ID = 2;
	student2.grade = 20;
	strcpy(student2.Name, "ali");
	students[1] = student2;
	



	struct Student student3;
	student3.ID = 3;
	student3.grade = 30;
	strcpy(student3.Name, "sayed");
	students[2] = student3;



	struct Student student4;
	student4.ID = 4;
	student4.grade = 40;
	strcpy(student4.Name, "khalid");
	students[3] = student4;
	


	struct Student student5;
	student5.ID = 5;
	student5.grade = 50;
	strcpy(student5.Name, "zed");
	students[4] = student5;
	

 	int location = binarySearchWithName(students, 0, 4, "khalid");
	printf("%d", students[location].ID);
	
    	

 //int location	= binarySearch(students, 0, 4, 1);
 //printf("%d \n", students[location].ID);
 //printf("%d \n", students[location].grade);
 
  



	_getch();
	

	return 0;
}
int binarySearch(struct Student data[], int begin, int end, int find) {

	int location = - 1;
	int lower = begin;
	int upper = end;
	int middle;
	
	if (lower <= upper)
	{
		
		middle = (lower + upper) / 2;
		if (data[middle].ID == find)
		{
			location = middle;
		}
		else if(data[middle].ID> find)
		{
			location = binarySearch(data, begin, middle-1, find);
		}
		else
		{
			location = binarySearch(data, middle + 1,  end, find);
		}

	}
	return location;
}