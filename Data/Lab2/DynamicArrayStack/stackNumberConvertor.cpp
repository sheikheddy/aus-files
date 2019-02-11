#include"stack.cpp"


int main()
{
	ItemType n;
	cout << "Please enter a base 10 integer: ";
	cin >> n;

	int option = -1;
	do{
		cout << "Convert the number from decimal into: "
			<< "\n 0 - Binary"
			<< "\n 1 - Octal"
			<< "\n 2 - Hexadecimal" << endl;
		cin.clear();
		cin >> option;

	}while(option < 0 || option > 2);

	StackType s;
	switch(option)
	{
		case 0:
	for(int i = n; i > 0; i/=2){
		s.Push(i%2);
	}		
	cout << "Binary: " << s << endl;
			break;
		case 1:
	for(int i = n; i > 0; i/=8){
		s.Push(i%8);
	}
	cout << "Octal: " << s << endl;
			break;
		case 2: 
	for(int i = n; i > 0; i/=16){
		s.Push(i%16);
	}
	cout << "Hex: " << s << endl;
			
			break;
	}
	

	return 0;
}
