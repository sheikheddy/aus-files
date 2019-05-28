#ifndef HashTable_H
#define HashTable_H
#include "Student.cpp"

//I hate ERROR_CODE and it sucks
enum ERROR_CODE{OVERFLOW, UNDERFLOW, SUCCESS};

class  HashTable	
{						
public : 			
	HashTable ( );
	void    RetrieveItem(Student&  item, bool&  found);
	ERROR_CODE InsertItem ( Student  item ); 	
	ERROR_CODE DeleteItem ( Student  item ); 	
	void print();
private :				
 
	Student	info[MAX_ITEMS] ;  
};        
#endif
