#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
using namespace std;

int A, B;


int main() {
	FastIO;


	cin >> A >> B;

	int summax = 0, summin = 0;
	int digit = 1;
	int d;

	while (A > 0 || B > 0) {
		d = A % 10;
		if (d == 5 || d == 6) {
			summax += 6 * digit;
			summin += 5 * digit;
		}
		else {
			summax += d * digit;
			summin += d * digit;
		}

		d = B % 10;
		if (d == 5 || d == 6) {
			summax += 6 * digit;
			summin += 5 * digit;
		}
		else {
			summax += d * digit;
			summin += d * digit;
		}

		digit *= 10;
		A /= 10;
		B /= 10;
	}

	cout << summin << " " << summax;

}
