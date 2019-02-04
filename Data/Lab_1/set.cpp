#include"set.h"

template<class T>
Set::Set(int size){
	max_size = size;
	arr = new T[max_size];
	eCount = 0;
	
}

template<class T>
Set::Set(const Set & s){
	max_size = s.getSize();
	arr = new T[max_size];
	eCount = s.getCount();

	for(int i = 0; i < eCount; ++i){
		arr[i] = s.getElementAt(i);
	}

}

Set::~Set(){
	delete arr;
}

int Set::getSize() const{
	return max_size;
}

int Set::getCount() const{
	return eCount;	
}

template<class T>
bool Set::insertElement(T value){
	if(!hasElement(value){
		if(eCount < maxSize){
			arr[++eCount] = value;
			return true;
		}
		else{
			return false;
		}
	}

}

template<class T>
bool Set::deleteElement(T value){
	if(!hasElement(value)){
		return false;
	}else{
	//delete element
	Set temp(max_size);
	int j = 0;
	for(int i = 0; i < eCount-1; ++i){
		if(getElementAt(i) != value){
			temp(j++) = arr[i];
		}

	}




}

template<class T>
bool Set::hasElement(T value){
	for(T element: arr){
		//would == fail on floats?
		if(element == value){
			return true;
		}
	}
	
	return false;
}

template<class T>
T Set::getElementAt(int i){
	return arr[i];
}

template<class T>
Set& Set::operator=(const Set& s){

	max_size = s.getSize();
	arr = new T[max_size];
	eCount = s.getCount();

	for(int i = 0; i < eCount; ++i){
		arr[i] = s.getElementAt(i);
	}

	return *this;
}

bool Set::operator==(Set& s) const{
	if(s.getCount() != eCount){
		return false;
	}

	for(int i = 0; i < eCount; ++i){
		if(!s.hasElement(arr[i]){
				return false;	
			}
	}

	return true;
}
bool Set::operator!=(Set& s) const{
	return !(s==this);
}


Set operator+(const Set& s1, const Set& s2){
	Set sum(s1);
	
	for(int i = 0; i < s2.getCount(); ++i){
		if(!s1.hasElement(s2.getElementAt(i))){
			sum.insertElement(s2.getElementAt(i));
		}
	}

	return sum;
}

Set operator-(const Set& s1, const Set& s2){
	Set difference(s1);


	for(int i = 0; i < s2.getCount(); ++i){
		if(s1.hasElement(s2.getElementAt(i))){
			difference.deleteElement(s2.getElementAt(i));
		}
	}

	return difference;
}

template<class T>
Set& Set::operator++(){
	for(T element: arr){
		++element;
	}
	
	return *this;
}

template<class T>
Set& Set::operator--(){
	for(T element: arr){
		--element;
	}

	return *this;
}



Set Set::operator++(int){
	Set temp(this);
	
	++(*this);

	return temp;
}


Set Set::operator--(int){
	Set temp(this);

	--(*this);

	return temp;
}

Set& Set::operator+=(Set& s){
	*this = *this + s;
	return *this;
}

Set& Set::operator-=(Set& s){
	*this = *this - s;
	return *this;
}


istream& operator>>(istream & cin, Set s){
	cout << "Enter " << s.getSize() << " elements." << endl;

	for(int i = 0; i < s.getSize(); ++i){
		cin >> arr[i];
	}



	return cin;
}

template<class T>
ostream& operator<<(ostream & cout, const Set& s){
	for(T element: arr){
		cout << element << " ";
	}

	return cout;
}


