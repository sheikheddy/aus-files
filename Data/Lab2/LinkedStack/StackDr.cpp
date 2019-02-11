#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "StackType.cpp"

using namespace std;

bool isInteger(char * s)
{
	if ((s[0] - '0') >= 0 && (s[0] - '0') <= 9)
		return true;
	else
		return false;
}
int main()
{
	StackType s;
	
	//This is for EX4
	char  pstfix[80];
	cout << "Enter post fix notation : ";
	cin.getline(pstfix, 80);

	char * pch;
	cout << "Splitting string " << pstfix << "  into tokens: " << endl;
	pch = strtok(pstfix, " ");
	while (pch != NULL)
	{
		if (isInteger(pch))
		{

			int i = atoi(pch);
			cout << "integer = " << i << endl;
			s.Push(i);
		}
		else{
			cout << "Operator = " << pch[0] << endl;
			ItemType b = s.Top(); s.Pop();
			ItemType a = s.Top(); s.Pop();
			switch(pch[0]){
				case '+':
					s.Push(a+b);
					break;
				case '-': 
					s.Push(a-b);
					break;
				case '/': 
					s.Push(a/b);
					break;
				case '*': 
					s.Push(a*b);
					break;
			}
			cout << "Result = " << s.Top() << endl; 
		}
		pch = strtok(NULL, " ");
	}

	system("pause");
	

  return 0;
}

