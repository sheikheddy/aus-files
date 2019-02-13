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

NodeType* p1;
NodeType* p2;//next

if( original.topPtr == NULL ){
    topPtr = NULL;
}else
{
    topPtr = new NodeType;
    topPtr->info = original.topPtr->info;

    p1 = topPtr;
    p2 = original.topPtr->next;
}

while( p2 != NULL )
{
    p1->next = new NodeType;
    p1 = p1->next;
    p1->info = p2->info;

    p2 = p2->next;
}
p1->next = NULL;
	
}

bool StackType::hasDuplicate() const
//naive O(N^2) approach
{
	if(this->IsEmpty()){return false;}

	StackType temp1(*this);
	StackType temp2(*this);
	try{
		while(!temp2.IsEmpty()){
			temp2.Pop();
			if(temp2.Top() == temp1.Top()){
				return true;
			}
		}
}catch(EmptyStack)
{	
	temp1.Pop();
	return temp1.hasDuplicate();
}
}

