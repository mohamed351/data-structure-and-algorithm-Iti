#define  _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<Windows.h>

struct Student {
	int ID;
	char Name[20];
	int grade[3];
};

struct Node {
	struct Student Data;
	struct Node *pleft;
	struct Node *pright;
};

struct Student FillStudent();
struct Node *CreateNode(struct Student data);
struct Node* InsertNode(struct Node *p, struct Student data);
void PrintStudent(struct Student data);
void printInorder(struct Node* node);
void printPreorder(struct Node* node);
void printPostorder(struct Node* node);


int main()
{
   
	struct Node *PRoot = NULL;
	struct Node *temp;
	int i = 0, size=0;
	
	printf("Please Enter your Number :  ");
	scanf("%d", &size);

	for (i = 0;i < size;i++)
	{
		struct Student student = FillStudent();

		PRoot = InsertNode(PRoot, student);

	}
	

	


	system("cls");
	temp = PRoot;
	printf("InOrder > \n");
	printInorder(temp);
	printf("\n_______________________________________________\n");


	temp = PRoot;
	printf("PreOrder > \n");
	printPreorder(temp);
	printf("\n_______________________________________________\n");


	temp = PRoot;
	printf("PostOrder > \n");
	printPostorder(temp);
	printf("\n_______________________________________________\n");

	

	
	_getch();

	return 0;
}

struct Student FillStudent() {
	struct Student student;
	int i;
	printf("please enter the Student ID : ");

	scanf("%d", &student.ID);

	printf("please enter your first name : ");
	scanf("%s", student.Name);

	printf("please enter grades : \n");
	for (i = 0;i < 3;i++)
	{

		printf("please enter the grade number %d : ", (i + 1));
		scanf("%d", &student.grade[i]);

	}
	printf("\n=================================\n");
	return student;


}

struct Node *CreateNode(struct Student data)
{
	struct Node *ptr;
	ptr = malloc(sizeof(struct Node));
	if (ptr)
	{
		ptr->Data = data;
		ptr->pleft = ptr->pright = NULL;

	}

	return ptr;


}
struct Node* InsertNode(struct Node *p, struct Student data) {
	if (p == NULL)
	{
		p = CreateNode(data);

	}
	else if (data.ID < p->Data.ID)
	{
		p->pleft = InsertNode(p->pleft, data);

	}
	else {
		p->pright = InsertNode(p->pright, data);
	}

	return p;

}
void PrintStudent(struct Student data) {
	int i = 0;
	printf("====================\n");
	printf("\n Id : %d ", data.ID);
	printf("Name : %s \n", data.Name);
	printf("grade number %d : %d \n", (i + 1), data.grade);
	printf("====================\n");

}
void printInorder(struct Node* node)
{
	if (node == NULL)
		return;


	printInorder(node->pleft);

	PrintStudent(node->Data);


	printInorder(node->pright);
}


void printPreorder(struct Node* node)
{
	if (node == NULL)
		return;


	PrintStudent(node->Data);
	printPreorder(node->pleft);
	printPreorder(node->pright);
}
void printPostorder(struct Node* node)
{
	if (node == NULL)
		return;

	printPostorder(node->pleft);


	printPreorder(node->pright);

	PrintStudent(node->Data);


}