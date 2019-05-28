#include<string>
using std::string;
class Student
{
private:
  int studentID;//student id
  string firstName;
  string lastName;
  int GPA;// Student record number
public:


//provide constructors
  //provide getters and setters
  //provide overloaded opeartors <, > == based on student id.
  //provide print function to  print student id and student record 
  //number

Student(){}
Student(int i,  string f, string l,int g): studentID(i), firstName(f), lastName(l), GPA(g){}

int getID() const{return studentID;}
int getGPA() const {return GPA;}
string getFirst() const {return firstName;}
string getLast() const {return lastName;}

//This is not programming. This is a waste of time.

void setID(int i){studentID = i;}
void setGPA(int g){GPA = g;}
void setFirst(string f){firstName = f;}
void setLast(string l){lastName = l;}

inline friend bool operator<(const Student& s1, const Student& s2){return s1.getID() < s2.getID();}
inline friend bool operator>(const Student& s1, const Student& s2){return s2 < s1;}
inline friend bool operator==(const Student& s1, const Student& s2){return s1.getID() == s2.getID();};

friend std::ostream& operator<<(std::ostream& cout, const Student& s){cout << s.getID() << " " << s.getFirst() << " " << s.getLast() << " " << s.getGPA();return cout;}; 

   
}; 



