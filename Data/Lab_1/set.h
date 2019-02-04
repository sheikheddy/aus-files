template<class T>
class  Set {
public:
	Set (int size=5 ); //default constructor
    	Set (const Set & s); // copy constructor
     	 ~Set (  ); //destructor
	int getSize ( ) const ;   // returns the max size of the Set
	int getCount ( )  const;// returns the  current number  of  elements  within Set
	bool insertElement ( T value); // insert value
	bool deleteElement ( T value); // delete value
	bool hasElement(T value); //checks if value belongs to Set


	//Having iter as a field doesn't make sense. Better to remove it.
	
	
	T getElementAt(int i); //returns value at i

	//Assignment
	Set& operator=(const Set& s);

	//Set equality
	bool operator==(Set& s) const;
	bool operator!=(Set& s) const;

	//These are implemented as non-member functions:
	//Union
	//Set operator+(const Set& s1, const Set& s2);
	//Set Difference
	//Set operator-(const Set& s1, const Set& s2);
	
	Set& operator+=(Set& s);
	Set& operator-=(Set& s);

	//What would it mean to increment or decrement a set? Is it a map that increments each element?
	Set& operator++();
	Set& operator--();
	Set operator++(int);
	Set operator--(int);
	
	friend istream& operator>>(istream & cin, Set s);
	friend ostream& operator<<(ostream & cout, const Set& s);
private:
int eCount;	// current number of elements within the set.
int max_size;
T  *arr ; // an array to store the Set elements.
};
