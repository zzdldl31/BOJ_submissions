#include <iostream>
using namespace std;

int N;

int main() {
	cin >> N;
	if (N == 1) {
		cout << 1 << " " << 0;
	}
	else if (N == 2) {
		cout << "impossible";
	}
	else if (N % 2 == 1) {
		cout << (N / 2 + 1) << " " << (N / 2);


	}
	else if (N % 4 == 0) {
		cout << (N / 4 + 1) << " " << (N / 4 - 1);


	}
	else {
		cout << "impossible";

	}
}