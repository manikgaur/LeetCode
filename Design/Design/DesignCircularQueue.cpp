#include "DesignCircularQueue.h"

DesignCircularQueue::DesignCircularQueue()
{
	file.open("DesignCircularQueueInput.txt");
}
class MyCircularQueue {
	int size;
	int front;
	int rear;
	vector<int> queue;
public:
	/** Initialize your data structure here. Set the size of the queue to be k. */
	MyCircularQueue(int k) {
		queue = vector<int>(k);
		size = k;
		front = 0;
		rear = -1;
	}

	/** Insert an element into the circular queue. Return true if the operation is successful. */
	bool enQueue(int value) {
		cout << value << " ";
		if (size == 0 || isFull())
			return false;

		rear = (rear + 1) % size;
		queue[rear] = value;
		cout << front << ", " << rear << endl;
		return true;
	}

	/** Delete an element from the circular queue. Return true if the operation is successful. */
	bool deQueue() {
		if (isEmpty())
			return false;

		if (front == rear) {
			rear = -1;
			front = 0;
		}
		else
			front = (front + 1) % size;
		cout << front << ", " << rear << endl;
		return true;
	}

	/** Get the front item from the queue. */
	int Front() {
		if (isEmpty())
			return -1;
		return queue[front];
	}

	/** Get the last item from the queue. */
	int Rear() {
		if (isEmpty())
			return -1;
		return queue[rear];
	}

	/** Checks whether the circular queue is empty or not. */
	bool isEmpty() {
		return size == 0 || rear == -1;
	}

	/** Checks whether the circular queue is full or not. */
	bool isFull() {
		if (isEmpty())
			return false;
		return ((rear + 1) % size) == front;
	}
};

void DesignCircularQueue::solve()
{
	fillInput();
	MyCircularQueue obj(qData[0]);
	int j = 1;
	for (int i = 1; i < queries.size(); i++)
	{
		if (queries[i] == "enQueue")
			cout << "enQueue :" << obj.enQueue(qData[j++]) << endl;
		else if (queries[i] == "deQueue")
			cout << "deQueue :" << obj.deQueue() << endl;
		else if (queries[i] == "Front")	
			cout << "Front :" << obj.Front() << endl;
		else if (queries[i] == "Rear")	
			cout << "Rear :" << obj.Rear() << endl;
		else if (queries[i] == "isEmpty")	
			cout << "isEmpty :" << obj.isEmpty() << endl;
		else if (queries[i] == "isFull")	
			cout << "isFull :" << obj.isFull() << endl;
		//cout << endl;
	}
		return;
}

void DesignCircularQueue::fillInput()
{
	getStrings(queries);
	getIntArray(qData);
}
