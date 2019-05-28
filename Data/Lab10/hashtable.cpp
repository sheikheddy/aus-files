#include<iostream>
#include<fstream>
#include "Student.cpp"
#include "UnsortedType.cpp"

#define ListType UnsortedType

enum ERROR_CODE{OVERFLOW, UNDERFLOW, SUCCESS};

class  hashtable	
{						
public : 			
	hashtable ( );
	~hashtable( );
	void    RetrieveItem(Student&  item, bool&  found) const;
	ERROR_CODE InsertItem ( Student  item ); 	
	ERROR_CODE DeleteItem ( Student  item ); 	
	void print();
private :				
 
	ListType* info[MAX_ITEMS] ;  
};  

	hashtable::hashtable(){
		for(int i = 0; i < MAX_ITEMS; ++i){
			info[i] = new ListType;	
		}	
	}
	
	hashtable::~hashtable(){
		for(int i = 0; i < MAX_ITEMS; ++i){
			if(info[i]){delete info[i];}	
		}	
	}
	
	
	void    hashtable::RetrieveItem(Student&  item, bool&  found) const{
		found = false;
		int hash = item.Hash();
		info[hash]->RetrieveItem(item, found);
	}

	ERROR_CODE hashtable::InsertItem ( Student  item ){
		int hash = item.Hash();
		info[hash]->InsertItem(item);
		if(info[hash] == nullptr){
			return OVERFLOW;
		}
		return SUCCESS;
		
	} 	
	ERROR_CODE hashtable::DeleteItem ( Student  item ){

			int hash = item.Hash();
			if(info[hash]==nullptr){
				return UNDERFLOW;
			}

			info[hash]->DeleteItem(item);
			return SUCCESS;
		}	
void	hashtable::print(){
		for(int i = 0; i < MAX_ITEMS; ++i){
			if(!(info[i]->IsEmpty())){
				Student s;
				info[i]->ResetList();
				for(int j = 0; j < info[i]->Length(); ++j){
				info[i]->GetNextItem(s);
				if(s.getID() != -1){
				std::cout << s << std::endl;
				}
				}
			}
		}
	}  



//One of the questions asks for us to print the student given their ID
//This is trivial to do with just the ID when the hash table is global
//Of course, in general, global variables are to be avoided
//So I made this non-member function that takes the table as a second argument
//And returns the student with their details all updated (if the ID exists in the table)
//If the ID is not found it just returns a student with ID = -1
//I still cannot fathom why Dr. Ghassan is so fond of "found"

	Student getStudent(int ID, const hashtable& table, bool& found){
		Student s(ID, "", "");
		table.RetrieveItem(s, found);
		return s;
	}


int main(){
	hashtable table;

	int ID;
	string fname;
	string lname;

	std::ifstream fin("student.txt");
	if(fin.fail()){std::cerr << "Error opening student file!"; exit(1);}

	while(fin >> ID >> fname >> lname){
		Student s(ID, fname, lname);
		if(table.InsertItem(s) == OVERFLOW){std::cout << "Could not insert student with ID" << ID << std::endl; break;}
	}
	
	fin.close();

	std::cout << "Students before deleting a person" << std::endl;
	table.print();
	
	bool found = false;
	Student s;
	while(!found){
	std::cout << "Enter student ID to retrieve and delete" << std::endl;
	std::cin >> ID;
	s = getStudent(ID, table, found);	
	}
	std::cout << "The student who you are removing/graduating is:" << std::endl;
	//making custom print functions is dumb when you can just do operator overloading
	std::cout << s << std::endl;
	table.DeleteItem(s);
	std::cout << "Students after you murdered/expelled that poor dude" << std::endl;
		
	table.print();
	
	return 0;
}
