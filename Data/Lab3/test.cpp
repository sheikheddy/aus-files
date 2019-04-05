/*
 *A program to test my implementation of the queue data structure
 *
 * */

#include"MarchingIndices.cpp"

void displayOptions();
void displayQueue(const QueueType& q);
QueueType initialize();
int main(){
	QueueType q;	
	ItemType front;
	ItemType rear;
	int option = 1;
	do{
		switch(option){
			case 1: q = initialize(); break;
			case 2: cin >> rear; cout << (q.Enqueue(rear) == Overflow ? "Overflow \n": " Enqueued "+ rear +"\n");  break;
			case 3: cout << (q.Dequeue(front) == Underflow ? "Underflow \n" : " Dequeued item " + front + "\n"); break; 
			case 4: displayQueue(q); break;
			case 5: cout << (q.IsFull() ? "Queue is full \n" : "Queue is not full \n"); break;
			case 6: cout << (q.IsEmpty() ? "Queue is empty \n" : "Queue is not empty \n"); break;
			case 7: q.MakeEmpty(); cout << "Queue Emptied \n"; break;
			case 8: break;
		}
		if(option != 8){
		displayOptions();
		cin >> option;
		}
	}while(option != 8);
		


	return 0;
}


void displayOptions(){
	cout << "Enter an Option: \n 1: Initialize a queue \2 2: Enqueue \n 3: Dequeue \n 4: Display Queue \n 5: Is Full? \n 6: Is Empty? \n 7: Make Empty \n 8: Exit" << endl;
}

QueueType initialize(){
	int n;
	cout << "Enter queue size: ";
	cin >> n;
	return QueueType(n);
}

void displayQueue(const QueueType& q){
	QueueType temporary(q);
	ItemType item;
	while(!temporary.IsEmpty()){
		temporary.Dequeue(item);
		cout << item << " ";
	}
	cout << endl;
}
