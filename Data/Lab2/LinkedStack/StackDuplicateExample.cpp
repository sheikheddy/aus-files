#include"StackType.cpp"
#include<iostream>
using namespace std;

const int SIZE = 5;

int main(){
	StackType s;

	cout << "Enter " << SIZE << " numbers" << endl;

	for(int i = 0; i < SIZE; ++i){
		int n;
		cin >> n;
		s.Push(n);
	}

	if(s.hasDuplicate()){cout << " Duplicates found " << endl;}
	else{cout << " No duplicates found " << endl;}

	return 0;
	
}
