#include<iostream>
#include<fstream>
using namespace std;

enum RelationType { LESS, EQUAL, GREATER } ;
class StudentType	// declares class data type
{
public :
RelationType    ComparedTo (StudentType  s)  const {
	return id == s.Getid() ? EQUAL : id < s.Getid() ? LESS : GREATER;
}
void  Print ( )  const {cout << id << "\t" << firstName << " " << lastName << "\t" << grade;}
void  Initialize ( int a, string b, string c ,  string d){
	id = a; firstName = b; lastName = c; grade = d;
}
int     Getid(){return id;} //I hate the way this is capitalized
string getGrade(){return grade;}
private :
int	id  ;
string firstName;
string lastName;
string grade;
};


