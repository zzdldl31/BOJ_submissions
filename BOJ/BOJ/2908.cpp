#include <iostream>
using namespace std;

int A, B;
int a, b;

int rev(int n) {
	int r = 0;
	while (n > 0) {
		r *= 10;
		r += n % 10;
		n /= 10;
	}
	return r;
}

int main() {
	cin >> A >> B;
	a = rev(A);
	b = rev(B);

	cout << (a > b ? a : b);
}