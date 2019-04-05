#include"QueueType.h"


	QueueType::QueueType(int max){
		maxQueue = max;
		items = new ItemType[maxQueue];
		front = rear = -1;

	} // PARAMETERIZED CONSTRUCTOR

	
    		
	void QueueType::MakeEmpty ( ){front = rear = -1;}			
	bool QueueType::IsFull( )const{
		return((rear == maxQueue - 1)&&(front == 0));
	}
	bool QueueType::IsEmpty( )const{
		return (front == -1);
	}
	ERROR_CODE QueueType::Enqueue( ItemType item ){
		if(IsFull()){return Overflow;}
		if(front == -1){front++;}
		if(rear == maxQueue - 1){
    			QueueType q(maxQueue);
			ItemType tmp;
			while(!IsEmpty()){
				Dequeue(tmp);
				q.Enqueue(tmp);
			}
			*this = q;
		}
		rear = rear + 1;
		items[rear] = item;
		return Success;
	}
	ERROR_CODE QueueType::Dequeue( ItemType&  item ){
		if(IsEmpty()){return Underflow;}
		item = items[front];
		front = front + 1;
		if(front == rear + 1){MakeEmpty();}
		return Success;
	
	}

	QueueType::~QueueType(){
		delete[] items;
	}

	QueueType& QueueType::operator=(const QueueType& q){
		if( q != this){
		if(maxQueue != q.maxQueue){
		maxQueue = q.maxQueue;
		delete items;
		items = new ItemType[maxQueue];
		}
		front = q.front;
		rear = q.rear;
		for(int i = 0; i < maxQueue; ++i){items[i] = q.items[i];}
		}
		return (*this);
	}

	QueueType::QueueType(const QueueType& q){
		maxQueue = q.maxQueue;
		items = new ItemType[maxQueue];
		front = q.front;
		rear = q.rear;
		for(int i = 0; i < maxQueue; ++i){items[i] = q.items[i];}
	}

