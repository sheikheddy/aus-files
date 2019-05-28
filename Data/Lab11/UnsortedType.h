#pragma once
#include <string>
#include<iostream>
#include<limits>
#define ItemType Edge

using std::string;

struct Edge
{
	string cityName;
	int weight;
	Edge(){cityName = ""; weight = std::numeric_limits<int>::max();}
	Edge(string  n, int wt){cityName = n; weight = wt;}
	Edge(Edge& a){cityName = a.cityName; weight = a.weight;}
	Edge operator=(const Edge& a){if(this!=&a){cityName = a.cityName; weight = a.weight;}return*this;}
	bool operator == (const Edge &a){return cityName==a.cityName;}
	bool operator != (const Edge &a){return cityName!=a.cityName;}
	void print(){std::cout << cityName << " " << weight << std::endl;} //prints cityName and weight.
	
};

struct NodeType{
	ItemType info;
	NodeType* next;
};

class UnsortedType
{
	
public:
	UnsortedType();
	
	UnsortedType(const UnsortedType& orginal);
	UnsortedType& operator=(const UnsortedType& orginal);
	~UnsortedType();
	void MakeEmpty();
	bool IsFull() const;
	int GetLength() const;
	ItemType GetItem(ItemType& item, bool& found) ;
	void PutItem(ItemType item);
	void DeleteItem(ItemType item);
	void ResetList();
	ItemType GetNextItem();
private:
	NodeType* listData;
	int length;
	NodeType* currentPos;
};


