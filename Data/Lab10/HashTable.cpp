#include<iostream>
#include<fstream>
#include"HashTable.h"
	HashTable::HashTable ( ){}
	//you should really just return a bool over here it would be so much better
	void    HashTable::RetrieveItem(Student&  item, bool&  found){
		found = false;
		int hash = item.Hash();
		for(int i = 0; i < MAX_ITEMS; ++i){
			if(info[(hash+i)%MAX_ITEMS] == item){
				item = info[(hash+i)%MAX_ITEMS];
				found = true; 
				break;
				}
		}

	}
	ERROR_CODE HashTable::InsertItem ( Student  item ){
		int i = 0;
		int hash = item.Hash();		
		while(info[(hash+i)%MAX_ITEMS].getID() != -1){
			if(++i == MAX_ITEMS){return OVERFLOW;}
		}
		info[(hash+i)%MAX_ITEMS] = item;
		return SUCCESS;
		

		
	} 	
	ERROR_CODE HashTable::DeleteItem ( Student  item ){
				int hash = item.Hash();
				for(int i = 0; i < MAX_ITEMS; ++i){
					if(info[(hash+i)%MAX_ITEMS] == item){
						info[(hash+i)%MAX_ITEMS].remove();
						break;
					}
				}
			}	
	void	HashTable::print(){
			for(Student s : info){
				if(s.getID() != -1){
					std::cout << s << std::endl;				
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

	Student getStudent(int ID, HashTable table, bool& found){
		Student s(ID, "", "");
		table.RetrieveItem(s, found);
		if(found){return s;}
		else{
			Student p;
			return p;
		}
	}


int main(){
	HashTable table;
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
