#include <istream>
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main() {
	char str[10];
	while (!(cin >> ws).eof()) {
		int A, S;
		cin >> A >> S;
		cout << A + S << endl;
	}
}
