/*
Author: Sheikh Abdul Raheem Ali
Description: Implementation of Stack Class
*/

#include "stack.h"


/*
Function Description: Constructor with passed size
Input: Integer
Output: A stack with maximum size max 
*/
StackType::StackType(int max)
{
	maxStack = max;
	top = -1;
	items = new ItemType [maxStack];
}
/*
Function Description: Default Constructor
Input: No input parameters
Output: A stack with the default maximum size 500
*/
StackType::StackType()
{
	maxStack = 500;
	top = -1;
	items = new ItemType [maxStack];
}
/*
Function Description: Copy Constructor
Input: const reference to a StackType object
Output: A deep copy of the original
*/
StackType::StackType(const StackType & original)  
{
	top = original.top;
	maxStack = original.maxStack;
	items = new ItemType[maxStack];
	for (int i=0; i <= top; i++)
		items[i] = original.items[i];
}

/*
Function Description: Destructor
Input: 
Output:
*/
StackType::~StackType()
{
	delete [] items;
}

/*
Function Description: Checks whether or not the stack is empty
Input: No input parameters
Output: True if the stack is empty, False otherwise
*/
bool StackType::IsEmpty() const
{
	return (top == -1) ;
}

/*
Function Description: Checks if the stack is full
Input: No input parameters
Output: True if the stack is full, False otherwise 
*/
bool StackType::IsFull() const
{
	return (top == maxStack-1);
}
/*
Function Description: Pushes (adds) an element newItem to the top of the stack
Input:  A value of type ItemType
Output: Overflow if the stack is full, otherwise success.
*/
Error_Code StackType::Push(ItemType newItem)
{
	if (IsFull()) return Overflow;
	top++;
	items[top] = newItem;
	return Success;
}

/*
Function Description: Pops (removes) the top element from the stack
Input: No input parameters
Output: Underflow is the stack is empty, otherwise success.
*/
Error_Code StackType::Pop()
{
	if (IsEmpty())
		return Underflow;
	top--;
	return Success;
}
/*
Function Description: Mutates passed item so that its value is changed to the value of the item at the top of the stack 
Input: An item that is passed by reference
Output: Underflow if stack is empty, success otherwise. 
*/
Error_Code  StackType::Top(ItemType& item) const
{
	if (IsEmpty())
		return Underflow;
	item  = items[top];
	return Success;
}

/*
Function Description: Logically removes all items from the stack
Input: No input parameters
Output: A stack that is now empty
*/
void StackType::Clear()
{
	top = -1;
}

/*
Function Description: Assignment operator
Input: constant reference to stack object
Output: A deep copy of the original
*/
StackType& StackType::operator=(const StackType& original)
{
	top = original.top;
        maxStack = original.maxStack;
        items = new ItemType[maxStack];
        for (int i=0; i <= top; i++)
                items[i] = original.items[i];
}

/*
Function Description: Stream insertion operator
Input: Output stream and constant reference to a stack object
Output: All items in the stack are printed to standard output as if they were popped 
*/

ostream& operator<<(ostream& cout, const StackType& s)
{
	for(int i=s.top; i>= 0; i--)
		cout << std::hex << s.items[i];
}

