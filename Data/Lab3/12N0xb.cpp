/*
 *A program to print all binary numbers from One to N using queues.
	Made by Sheikh Abdul Raheem Ali
 * */

#include"CircularArray.cpp"

int main(){

	int n;
	do{
	cout << "Enter a number: ";
	cin >> n;
	}while(n < 1);

	string str = "1";
	QueueType q(n);
	q.Enqueue(str);

	cout << "Binary numbers from 1 to " << n << " are: \n";
	for(int i = 1; i <= n; ++i){
		q.Dequeue(str);
		cout << str << endl;
		q.Enqueue(str+"0");
		q.Enqueue(str+"1");
	}


return 0;
}
