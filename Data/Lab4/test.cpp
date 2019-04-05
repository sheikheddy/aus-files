#include"UnsortedType.cpp"

int main(){

	//This feels like a waste of time. What am I learning? 

	Book b(1234,"Title","Author", "Publisher", 5.0, 2);

	cout << b << endl; //tests Book::print() 

	b.sellBook(1);

	cout << "Copies after selling one book: " << b.getNumCopies() << endl;

	b.buyBook(5);

	cout << "Copies after buying five books: " << b.getNumCopies() << endl;


	cout << b.getISBN() << " " << b.getAuthor() << " " << b.getTitle() << " " << b.getPublisher() << " " << b.getPrice() << endl;

	UnsortedType lib;
        Book a(1000, "T", "A", "P", 4.2, 6);
	lib.InsertItem(a);
	lib.InsertItem(b);

	 if(lib.IsFull()){
	 	cout << "List is full" << endl;
	 }else{
	 	cout << "List is not full" << endl;
	 }
	 
	 cout << "The length of the list is currently " << lib.LengthIs() << endl;
	
	cout << "The library before removing TAP is: " << endl;

	printLib(lib); //also tests ResetList, GetNextItem

	lib.DeleteItem(a); //also tests RetrieveItem

	cout << "The Library after removing TAP is: " << endl;

	printLib(lib);

	lib.InsertItem(a);

	cout << "Now we'll enter a book! What is the ISBN?" << endl;

	int isbn;
	cin >> isbn;

	cin.ignore(1000, '\n');

	string title, author, publisher;

	cout << "Title?";  getline(cin, title);
	cout << "Author?"; getline(cin, author);
	cout << "Publisher?"; getline(cin, publisher);
	
	float price;
	
	cout << "Price?"; cin >> price;

	int numcopies;

	cout << "Number of Copies?"; cin >> numcopies;


	//I know it's a bad practice to not validate user input.
	//But if the user inputs something that breaks the program
	//And the user is me
	//Then the user is dumb and should run the program again

	Book c(isbn, title, author, publisher, price, numcopies);

	lib.InsertItem(c);

	UnsortedType x, y;
	lib.Split(x,y,"P");

	cout << "The books published by the illustrious and prestigious P are: " << endl;

	printLib(x);

	cout << "The books published by other people are: " << endl;

	printLib(y);

	UnsortedType z;

	lib.Order(z);

	cout << "The books which we need to order more copies of are: " << endl;

	printLib(z);

	return 0;
}
