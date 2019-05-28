#include"Vertex.h"
Vertex::Vertex(){ //default constructor
	name = "";
}	
	Vertex::Vertex(string  n){ //constructor with argument
	name = n;
}
	Vertex::Vertex( Vertex& a){ //copy constructor
	name = a.getName();
	edges = a.edges;
}
	Vertex Vertex::operator=(const Vertex& a){//assignment operator
	
	if(this != &a){	

	name = a.getName();
	edges = a.edges;

	}
	return *this;
}
bool Vertex::operator == (const Vertex &a){//compares vertices with names only
	return name == a.getName();
}
bool Vertex::operator != (const Vertex &a){ //compares vertices with names only
	return name != a.getName();
}
bool Vertex::addEdge(string edgeName, int weight){// Adds an edge.
	Edge e(edgeName, weight);
	try{	
	edges.PutItem(e);
	return true;
	}catch (std::bad_alloc exception)
	{
		return false;
	}
}
string Vertex::getName() const{//return the name
	return name;
}
void Vertex::print(){//print vertex name and its edges. 
	if(name != ""){
	std::cout << name << " to " <<std::endl;

	//I do not call ResetList() because GetNextItem loops around
	for(int i = 0; i < edges.GetLength(); ++i){
		std::cout << "\t"; 
		edges.GetNextItem().print();
		}
	}
}

bool Vertex::hasEdge(string edgeName){
	bool found;
	Edge e(edgeName, 0);
	edges.GetItem(e, found);
	return found;
}

//Non-class functions

const int SIZE = 10;

void displayOptions();
//reminder: arrays are always passed by reference
void makeDecision(int option, Vertex graph[]);
//these functions would be nice if we made Vertex[] iterable
void addVertex(Vertex graph[]);
void addEdge(Vertex graph[]);
bool exists(string a, Vertex graph[]);

int main(){

	Vertex graph[SIZE];

	int option;
	displayOptions();
	do{
	std::cout << "Choose an option: ";
	std::cin >> option;
	std::cin.ignore();
	makeDecision(option, graph);
	}while(option != 4);

	
	return 0;
}

void displayOptions(){
	std::cout << "1. Add Vertex\n"	\
		  << "2. Add an Egde\n"	\
		  << "3. Print Graph\n"	\
		  << "4. Exit"	<< std::endl;
}

void makeDecision(int option, Vertex graph[]){
	switch(option){
	case 1: addVertex(graph); break;
	case 2: addEdge(graph); break;
	case 3: for(int i = 0; i < SIZE; ++i){graph[i].print();} break;
	case 4: std::cout << "Goodbye!" << std::endl; break;
	default: std::cout << "Please enter a valid option" << std::endl;break;
	}
}

void addVertex(Vertex graph[]){
	std::cout << "Enter name: " << std::endl;
	string n;
	getline(cin, n);
	Vertex v(n);
	for(int i = 0; i < SIZE; ++i){
		if(graph[i] == v){std::cout << "Vertex already in graph" << std::endl; return;}
		if(graph[i].getName() == ""){graph[i] = v; return;}
	}
	std::cout << "Graph is full!" << std::endl;			
}
void addEdge(Vertex graph[]){
	std::cout << "Enter Source: " << std::endl;
	string source;
	getline(std::cin, source);
	if(!exists(source, graph)){std::cout << "Source does not exist" << endl; return;}

	std::cout << "Enter Destination: " << std::endl;
	string destination;
	getline(std::cin, destination);
	if(!exists(destination, graph)){std::cout << "Destination does not exist" << endl; return;}

	std::cout << "Enter weight: " << std::endl;
	int wt;
	std::cin >> wt;	

	for(int i = 0; i < SIZE; ++i){
		if(graph[i].getName() == source){
			if(graph[i].hasEdge(destination)){
				std::cout << "Edge already exists between " << source << " and " << destination << std::endl;
			}else{
				graph[i].addEdge(destination, wt);
			}
			return;			
		}
	}
	
}

bool exists(string str, Vertex graph[]){
	for(int i = 0; i < SIZE; ++i){
		if(graph[i].getName() == str){return true;}
		if(graph[i].getName() == ""){return false;}
	}
}
