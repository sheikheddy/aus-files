#ifndef Queue_H
#define Queue_H

class FullQueue
{};

class EmptyQueue
{};

template <class ItemType>
struct NodeType;

template <class ItemType>
class Queue
{
public:
  Queue();
  ~Queue();
  void MakeEmpty();
  void Enqueue(ItemType);
  void Dequeue(ItemType&);
  bool IsEmpty() const;
  bool IsFull() const;
private:
  NodeType<ItemType>* front;
  NodeType<ItemType>* rear;
};

#endif