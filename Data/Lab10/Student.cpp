
#include<string>
using std::string;
const int MAX_ITEMS= 101;
class Student
{
private:
  int studentID;//student id
  string firstName;
  string lastName;
public:


//provide constructors
  //provide getters and setters
  //provide overloaded opeartors <, > == based on student id.
  //provide print function to  print student id and student record 
  //number

Student(){studentID = -1;}
Student(int i,  string f, string l): studentID(i), firstName(f), lastName(l){}

//deliberately chosen so there is at least one collision
int Hash(){return studentID%MAX_ITEMS;}

int getID() const{return studentID;}
string getFirst() const {return firstName;}
string getLast() const {return lastName;}


//copy constructor
 Student(const Student & s): Student(s.studentID, s.firstName, s.lastName){}
~Student(){}

 Student&operator=(const Student& s){
	if(this != &s){
		studentID = s.studentID;
		firstName = s.firstName;
		lastName = s.lastName;
	}
	return *this;
	
}

/*
	I'm going to assume the ID of a student never changes once assigned, and therefore there's no need to provide a mutator.

	Why? Consider the case where hash(old_ID) = a, and hash(new_ID) = b, where a !=b. 
	Moving student from info[a] to info[b] would remove a lot of the elegance of our solution
*/

void remove(){studentID = -1;}
void setFirst(string f){firstName = f;}
void setLast(string l){lastName = l;}

inline friend bool operator<(const Student& s1, const Student& s2){return s1.getID() < s2.getID();}
inline friend bool operator>(const Student& s1, const Student& s2){return s2 < s1;}
inline friend bool operator==(const Student& s1, const Student& s2){return s1.getID() == s2.getID();};

friend std::ostream& operator<<(std::ostream& cout, const Student& s){cout << s.getID() << " " << s.getFirst() << " " << s.getLast();return cout;}; 

   
}; 



