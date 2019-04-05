#include<iostream>
#include<string>
using namespace std;

const  int  MAX_ITEMS = 50 ;
enum  RelationType { LESS, EQUAL, GREATER } ;


class  Book		// declares class data type
{						
public : 			//  3 public member functions
      Book();
      Book(int, string,string,string,float,int);
      Book(const Book & b);
      ~Book();
      Book& operator=(const Book& b);
      
      
      int sellBook(int count); //decrements the number of copies 
      int buyBook(int count); //increments the number of copies
      RelationType ComparedTo (const Book &)const; //Compare with   ISBN
      void print ( )  const ; //prints book info
      int getISBN(){return isbn;}
      string getAuthor(){return author;}

      string  getTitle(){return title;}
      float getPrice(){return price;}
      int getNumCopies(){return numCopies;}
      string getPublisher(){return publisher;}

      friend ostream& operator<<(ostream& cout, const Book& b);
private :		
      int	isbn;
      string  author;
      string  title;
      float   price;
      int numCopies;
      string publisher;
} ;

Book::~Book(){

}

Book::Book(int ISBN, string Title, string Author, string Publisher, float Price, int NumCopies){
	isbn = ISBN; 
	author = Author; 
	publisher = Publisher;
	title = Title;
	price = Price; 
	numCopies = NumCopies; 
}

Book::Book(){

}

Book::Book(const Book& b){

	isbn = b.isbn; 
	author = b.author; 
	title = b.title; 
	price = b.price; 
	numCopies = b.numCopies; 
	publisher = b.publisher;
	
	
}

Book& Book::operator=(const Book& b){

	isbn = b.isbn; 
	author = b.author; 
	title = b.title; 
	price = b.price; 
	numCopies = b.numCopies; 
	publisher = b.publisher;
	
	return *this; 
}
int Book::sellBook(int count){
	if(numCopies - count < 0){
		cout << "Cannot sell "<< count << " copies." << endl;
		return -1;
	}
	numCopies -= count;
	return numCopies;
}

int Book::buyBook(int count){
	numCopies += count;
	return numCopies;
}

RelationType Book::ComparedTo(const Book & b) const{
	if(isbn < b.isbn){return LESS;}
	if(isbn == b.isbn){return EQUAL;}
	if(isbn > b.isbn){return GREATER;} 
}

void Book::print() const{
	cout <<	"ISBN: " << isbn << " Title: " << title << " Author: "<< author << " Publisher: " << publisher << " Price: " << price << " Number of Copies: " << numCopies;
}


ostream& operator<<(ostream& cout, const Book& b){
	b.print();
	return cout;
}
