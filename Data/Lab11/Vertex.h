#include"UnsortedType.cpp"

class Vertex
{
public:
	Vertex(); //default constructor	
	Vertex(string  n); //constructor with argument
	Vertex( Vertex& a); //copy constructor
	Vertex operator=(const Vertex& a);//assignment operator
	
bool operator == (const Vertex &a);//compares vertices with names only
bool operator != (const Vertex &a); //compares vertices with names only
bool addEdge(string edgeName, int weight);// Adds an edge.
string getName() const;//return the name
void print();//print vertex name and it’s edges. 
bool hasEdge(string edgeName);

private:
	string name;
	UnsortedType edges;
};
