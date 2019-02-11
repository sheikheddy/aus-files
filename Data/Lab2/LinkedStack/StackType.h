#pragma once

typedef int ItemType;
class FullStack {};
class EmptyStack {};
struct NodeType
{
	ItemType info;
	NodeType* next;
};
class StackType
{
public:
	StackType();
	~StackType();

	void Push(ItemType newItem);
	void Pop();
	ItemType Top();
	
	bool IsFull() const;
	bool IsEmpty() const;

	//Functions created by me start here
	StackType(const StackType &);
	bool hasDuplicate() const;
	//and end here

private:	
	NodeType* topPtr;
};
