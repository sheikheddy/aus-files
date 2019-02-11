// Implementation file for linked StackType
#include "StackType.h"
#include <new>


void StackType::Push(ItemType newItem)
// Adds newItem to the top of the stack.
// Stack is bounded by size of memory.
// Pre:  Stack has been initialized.
// Post: If stack is full, FullStack exception is thrown;
//       else newItem is at the top of the stack.

{
  if (IsFull())
    throw FullStack();
  else
  {
    NodeType* location;
    location = new NodeType;
    location->info = newItem;
    location->next = topPtr;
    topPtr = location;
  }
}
void StackType::Pop()
// Removes top item from Stack and returns it in item.
// Pre:  Stack has been initialized.
// Post: If stack is empty, EmptyStack exception is thrown;
//       else top element has been removed.
{
  if (IsEmpty())
    throw EmptyStack();
  else
  {  
    NodeType* tempPtr;
    tempPtr = topPtr;
    topPtr = topPtr->next;
    delete tempPtr;
  }
}

ItemType StackType::Top()
// Returns a copy of the top item in the stack.
// Pre:  Stack has been initialized.
// Post: If stack is empty, EmptyStack exception is thrown;
//       else a copy of the top element is returned.
{
  if (IsEmpty())
    throw EmptyStack();
  else
    return topPtr->info;  
}

StackType::StackType()	// Class constructor.
{
  topPtr = NULL;
}
bool StackType::IsFull() const
// Returns true if there is no room for another ItemType 
//  on the free store; false otherwise.
{
    NodeType* location;
  try
  {
    location = new NodeType;
    delete location;
    return false;
  }
  catch(std::bad_alloc exception)
  {
    return true;
  }
}

StackType::~StackType()
// Post: stack is empty; all items have been deallocated.
{
  NodeType* tempPtr;

  while (topPtr != NULL)
  {
    tempPtr = topPtr;
    topPtr = topPtr->next;
    delete tempPtr;
  }
}

bool StackType::IsEmpty() const
{
  return (topPtr == NULL);
}  

StackType::StackType(const StackType & original){
	NodeType* ptr = original.topPtr;
	while(ptr != NULL){
	NodeType* location = new NodeType;
	location->info = ptr->info;
	location->next = topPtr->next;
	topPtr = location;
	ptr = ptr->next;
	}
	
}

bool StackType::hasDuplicate() const
//naive O(N^2) approach
{
	StackType temp1(*this);
	StackType temp2(temp1);
	while(!temp1.IsEmpty()){
		temp2.Pop();
		while(!temp2.IsEmpty()){
			if(temp2.Top() == temp1.Top()){
				return true;
			}
			temp2.Pop();
		}
		temp1.Pop();
	}
	return false;
}

