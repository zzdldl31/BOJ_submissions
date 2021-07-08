#include <iostream>
using namespace std;

int ind;
int mm;

int main() {
	for (int i = 0; i < 9; i++) {
		int n;
		cin >> n;
		if (i == 0) {
			ind = 1;
			mm = n;
		}
		else if (mm < n) {
			mm = n;
			ind = i + 1;
		}
	}
	cout << mm << endl << ind;
}