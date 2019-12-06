struct Queue {
	int size;
	int Rear;
	int Front;
	int * Data;
	
};
int Enqueue(struct Queue * q, int data)
{
	int retval = 0;
	
	if (q->Rear !=q->size -1) {
		q->Rear++;
		q->Data[q->Rear]=data;
		retval = 1;

	}
	return retval;

}
int Dequeue(struct Queue *q) {
	int retval = 0;
	if (q->Front != q->Rear)
	{
		q->Front++;
		retval = q->Data[q->Front];
		
	}
	return retval;
}