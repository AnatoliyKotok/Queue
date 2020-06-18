#include <iostream>
#include"Stack.h"
#include<ctime>
using namespace std;

int main() {
	srand(time(0));
	Queue<int>Q;
	Q.push(13,12);
	Q.push(15, 2);
	Q.push(23, 5);
	Q.print();
	cout << Q.isEmpty() << endl;
	cout << Q.pop() << endl;
    Q.print();
}