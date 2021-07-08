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
		if (A == 0 && S == 0)
			return 0;
		cout << A + S << endl;
	}
}
