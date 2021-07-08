#include <iostream>
using namespace std;

int rem[42];

int main() {
	for (int i = 0; i < 10; i++) {
		int q;
		cin >> q;
		rem[q % 42]++;
	}
	int cnt = 0;
	for (int i = 0; i < 42; i++)
		if (rem[i] > 0)
			cnt++;

	cout << cnt;
}