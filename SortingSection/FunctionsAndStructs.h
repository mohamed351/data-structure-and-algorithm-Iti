#pragma region StructAndArray
struct Student {
	int id;
	char Name[20];
	int grade;

};
struct Student data[5];
#pragma endregion

#pragma region ProtoTypes

void FillTestingData(void);
void MergeSort(int low, int hight);
void Merge(int low, int mid, int hight);
void BubbleSortPrint(struct Student *studentd, int size);
int binarySearch(struct Student data[], int begin, int end, int find);
void PrintStudent(struct Student data);
void BubbleSort(struct Student *studentd, int size);
int binarySearchWithName(struct Student data[], int begin, int end, char *Name);
//struct Student FillStudent();

#pragma endregion

#pragma region Functions
void MergeSort(int low, int hight) {
	int mid = (low + hight) / 2;
	if (low < hight)
	{
		MergeSort(low, mid);
		MergeSort(mid + 1, hight);
		Merge(low, mid, hight);

	}

}
void Merge(int low, int mid, int hight) {
	int i;
	int loc = low;
	int list1 = low;
	int list2 = mid + 1;
	struct Student temp[5];
	while (list1 <= mid && list2 <= hight)
	{
		if ((data[list1].id) < (data[list2].id)) {
			temp[loc] = data[list1];
			loc++;
			list1++;
		}
		else
		{
			temp[loc] = data[list2];
			loc++;
			list2++;
		}
	}
	while (list1 <= mid)
	{
		temp[loc] = data[list1];
		loc++;
		list1++;


	}
	while (list2 <= hight) {
		temp[loc] = data[list2];
		loc++;
		list2++;
	}
	for (i = low;i <= hight;i++)
	{
		data[i] = temp[i];
	}


}
void FillTestingData()
{

	struct Student std1;
	struct Student std2;
	struct Student std3;
	struct Student std4;
	struct Student std5;

	std2.id = 3;

	std2.grade = 30;




	std1.id = 2;
	std1.grade = 20;


	std3.id = 4;
	std3.grade = 40;


	std4.id = 5;
	std4.grade = 50;


	std5.id = 1;
	std5.grade = 10;

	//manage Names

	strcpy(std1.Name, "Sayed");
	strcpy(std2.Name, "Ali");
	strcpy(std3.Name, "Karem");
	strcpy(std4.Name, "Zed");
	strcpy(std5.Name, "Bob");
	data[0] = std2;
	data[1] = std1;
	data[2] = std3;
	data[3] = std4;
	data[4] = std5;

}
void BubbleSortPrint(struct Student *studentd, int size)
{
	int i, x = 0;
	struct Student temp;

	for (i = 0;i < size;i++)
	{
		for (x = 0;x < size;x++)
		{
			if (((int)studentd[x + 1].Name[0]) <= ((int)studentd[x].Name[0]))
			{
				if (x + 1 < size)
				{
					temp = studentd[x + 1];
					studentd[x + 1] = studentd[x];
					studentd[x] = temp;
				}



			}
		}
	}
	//you can call it outside the array
	
		for (i = 0; i < 5; i++)
		{
			printf("id: %d \n", data[i].id);
			printf("grade: %d\n", data[i].grade);

			printf("name : %s \n", data[i].Name);
			printf("____________________\n");

		}

	

}
int binarySearch(struct Student data[], int begin, int end, int find) {

	int location = -1;
	int lower = begin;
	int upper = end;
	int middle;

	if (lower <= upper)
	{

		middle = (lower + upper) / 2;
		if (data[middle].id == find)
		{
			location = middle;
		}
		else if (data[middle].id > find)
		{
			location = binarySearch(data, begin, middle - 1, find);
		}
		else
		{
			location = binarySearch(data, middle + 1, end, find);
		}

	}
	return location;
}
void PrintStudent(struct Student data) {
	int i=0;
	printf("====================\n");
	printf("\n Id : %d ", data.id);
	printf("Name : %s \n", data.Name);
	printf("grade number %d : %d \n", (i + 1), data.grade);
	printf("====================\n");
	
}
void BubbleSort(struct Student *studentd, int size) {
	int i, x = 0;
	struct Student temp;

	for (i = 0;i < size;i++)
	{
		for (x = 0;x < size;x++)
		{
			if (((int)studentd[x + 1].Name[0]) <= ((int)studentd[x].Name[0]))
			{
				if (x + 1 < size)
				{
					temp = studentd[x + 1];
					studentd[x + 1] = studentd[x];
					studentd[x] = temp;
				}



			}
		}
	}
}
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
		else if (data[middle].Name[0] > Name[0])
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
//struct Student FillStudent() {
//	struct Student student;
//	int i;
//	printf("please enter the Student ID : ");
//
//	scanf("%d", &student.ID);
//
//	printf("please enter your first name : ");
//	scanf("%s", student.Name);
//
//	printf("please enter grades : \n");
//	for (i = 0;i < 3;i++)
//	{
//
//		printf("please enter the grade number %d : ", (i + 1));
//		scanf("%d", &student.grade[i]);
//
//	}
//	return student;
//
//
//}
#pragma endregion