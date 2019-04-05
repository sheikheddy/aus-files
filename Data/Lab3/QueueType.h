#ifndef QUEUETYPE_H

#define QUEUETYPE_H

#include<iostream>
#include<string>
using namespace std;

enum ERROR_CODE{Underflow, Overflow, Success};


typedef string ItemType;
class QueueType {
public:
	QueueType( int max = 10); // PARAMETERIZED CONSTRUCTOR
    	void MakeEmpty ( );			
	bool IsFull( ) const;
	bool IsEmpty( ) const;
	ERROR_CODE Enqueue( ItemType item );
	ERROR_CODE Dequeue( ItemType&  item );
   // Add the definition of the safety functions

	~QueueType(); //Destructor
	QueueType(const QueueType& q); //Copy Constructor
	QueueType& operator=(const QueueType& q); //Assigment operator
private:
	int maxQueue;        // Queue capacity	
	ItemType*  items; // DYNAMIC ARRAY IMPLEMENTATION 
	int front;
	int rear;                                       
	int count;
};

#endif
