#include<iostream>
#include<cstdlib>
using namespace std;

struct queue
{
	int data;
	struct queue *next;
};

typedef struct queue queue;

queue *front = NULL;
queue *rear = NULL;

bool isEmpty()
{
	if(front == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void enQueue(int data)
{
	queue *naya;
	naya = (queue*)malloc(sizeof(queue));
	if(!naya)
	{
		cout << "memory error\n";
		return;
	}	
	naya->next = NULL;
	naya->data = data;
	if(isEmpty())
	{
		front = rear = naya;
		return;
	}
	rear->next = naya;
	rear = naya;
}

int deQueue()
{
	if(isEmpty())
	{
		cout << "queue empty\n";
		return 0;
	}
	queue *temp;
	int x = front->data;
	temp = front;
	if(front == rear)
	{
		front = NULL;
		rear = NULL;
		free(temp);
		return x;
	}
	front = front->next;
	free(temp);
	return x;
}

void checkEnd()
{
	if(isEmpty())
	{
		cout << "queue empty\n";
	}
	else
	{
		cout << rear->data << endl;;
	}
}

int main()
{
	char ch;
	do
	{
		cout << "what do you want to do?\n(e)nQueue\n(d)eQueue\n(c)heckEnd\n(i)sEmpty\ne(x)it\n";
		cin >> ch;
		switch(ch)
		{
			case 'e': int x; cin >> x; enQueue(x); break;
			case 'd': cout << deQueue() << endl; break;
			case 'c': checkEnd(); break;
			case 'i': cout << isEmpty() << endl; break;
		}
	}
	while(ch != 'x');
	return 0;
}
