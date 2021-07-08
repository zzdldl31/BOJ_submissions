#include <iostream>
using namespace std;

int hh, mm;

int main() {
	cin >> hh >> mm;
	if (mm >= 45) {
		cout << hh << " " << (mm - 45);
	}
	else {
		mm += 60 - 45;
		hh -= 1;
		if (hh < 0)
			hh += 24;
		cout<< hh << " " << mm;
	}
}