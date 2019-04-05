#include"QueueType.h"


	QueueType::QueueType(int max){
		maxQueue = max;
		front = 0;
		rear = maxQueue - 1;
		count = 0;
		items = new ItemType[maxQueue];


	} // PARAMETERIZED CONSTRUCTOR

	
    		
	void QueueType::MakeEmpty ( ){count = 0; front = (rear + 1) % maxQueue;}			
	bool QueueType::IsFull( )const{return count == maxQueue;}
	bool QueueType::IsEmpty( )const{return count == 0;}
	ERROR_CODE QueueType::Enqueue( ItemType item ){
		if(IsFull()){return Overflow;}
		rear = (rear + 1) % maxQueue;
		items[rear] = item;
		count++;
		return Success;
	}
	ERROR_CODE QueueType::Dequeue( ItemType&  item ){
		if(IsEmpty()){return Underflow;}
		item = items[front];
		front = (front + 1) % maxQueue;
		count--;
		return Success;
	
	}

	QueueType::~QueueType(){
		delete[] items;
	}

	QueueType& QueueType::operator=(const QueueType& q){
		if(q != this){ 
		if(maxQueue != q.maxQueue){
			maxQueue = q.maxQueue;
			delete[] items;
			items = new ItemType[maxQueue];
		}
		front = q.front;
		rear = q.rear;
		count = q.count;
		for(int i = 0; i < maxQueue; ++i){items[i] = q.items[i];}
		}
		return (*this);
	}

	QueueType::QueueType(const QueueType& q){
		maxQueue = q.maxQueue;
		items = new ItemType[maxQueue];
		front = q.front;
		rear = q.rear;
		count = q.count;
		for(int i = 0; i < maxQueue; ++i){items[i] = q.items[i];}
	}
