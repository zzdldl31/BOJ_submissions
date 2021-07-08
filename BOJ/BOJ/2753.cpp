#include <iostream>
using namespace std;

int year;

int main() {
	cin >> year;
	bool isy = false;
	if (year % 4 == 0) {
		isy = true;
		if (year % 100 == 0) {
			isy = false;
			if (year % 400 == 0) {
				isy = true;
			}
		}
	}
	cout << (isy ? 1 : 0);
}
