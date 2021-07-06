#include <iostream>
#include <string>
using namespace std;

string str;


int main() {
	cin >> str;
	int n = str.length();
	n -= 2;
	cout << 'h';
	for (int i = 0; i < 2 * n; i++)
		cout << 'e';
	cout << 'y';


}