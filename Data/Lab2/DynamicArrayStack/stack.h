/*
Author: 
Class Description:
*/
#ifndef STACKTYPE_H
#define STACKTYPE_H

#include <iostream>
using namespace std;
typedef int ItemType;
enum Error_Code  {Success, Overflow, Underflow};

class StackType {	
public:
	StackType();
	StackType (const StackType & ); 
	StackType(int max); 

	bool IsFull () const;
	bool IsEmpty() const;
	Error_Code Push( ItemType  );
	Error_Code Pop();
	Error_Code Top(ItemType &) const;

	//Functions that I created start here
	void Clear();
	
	StackType& operator=(const StackType &);
	friend ostream& operator<<(ostream& , const StackType &);

	//and end here

	~StackType();

private:
	int top;
	int maxStack;
	ItemType*  items;	
};
#endif




