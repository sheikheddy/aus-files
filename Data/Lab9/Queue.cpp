#ifndef Queue_CPP
#define Queue_CPP

#include <cstddef>                // For NULL.
#include <new>                    // For bad_alloc.
#include "Queue.h"

;template <class ItemType>
struct NodeType
{
  ItemType info;
  NodeType<ItemType>* next;
};

template <class ItemType>
Queue<ItemType>::Queue()         // Class constructor.
// Post: front and rear are set to NULL.
{
  front = NULL;
  rear = NULL;
}

template <class ItemType>
void Queue<ItemType>::MakeEmpty()
// Post: Queue is empty; all elements have been deallocated.
{
  NodeType<ItemType>* tempPtr;

  while (front != NULL)
  {
    tempPtr = front;
    front = front->next;
    delete tempPtr;
  }
  rear = NULL;
}
template <class ItemType>          // Class destructor.
Queue<ItemType>::~Queue()
{
  MakeEmpty();
}

template<class ItemType>
bool Queue<ItemType>::IsFull() const
// Returns true if there is no room for another NodeType object
//  on the free store and false otherwise.
{
  NodeType<ItemType>* location;
  try
  {
    location = new NodeType<ItemType>;
    delete location;
    return false;
  }
  catch(std::bad_alloc exception)
  {
    return true;
  }
}

template <class ItemType>
bool Queue<ItemType>::IsEmpty() const
// Returns true if there are no elements on the queue and false otherwise.
{
  return (front == NULL);
}

template <class ItemType>
void Queue<ItemType>::Enqueue(ItemType newItem)
// Adds newItem to the rear of the queue.
// Pre:  Queue has been initialized.
// Post: If (queue is not full), newItem is at the rear of the queue:
//       otherwise, a FullQueue exception is thrown.

{
  if (IsFull())
    throw FullQueue();
  else
  {
    NodeType<ItemType>* newNode;

    newNode = new NodeType<ItemType>;
    newNode->info = newItem;
    newNode->next = NULL;
    if (rear == NULL)
      front = newNode;
    else
      rear->next = newNode;
    rear = newNode;
  }
}

template <class ItemType>
void Queue<ItemType>::Dequeue(ItemType& item)
// Removes front item from the queue and returns it in item.
// Pre:  Queue has been initialized
// Post: If (queue is not empty). the front of the queue has been
//       removed and a copy returned in item;
//       otherwise, an EmptyQueue exception is thrown.
{
  if (IsEmpty())
    throw EmptyQueue();
  else
  {
    NodeType<ItemType>* tempPtr;

    tempPtr = front;
    item = front->info;
    front = front->next;
    if (front == NULL)
      rear = NULL;
    delete tempPtr;
  }
}

#endif