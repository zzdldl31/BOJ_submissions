#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
#include <iomanip>
using namespace std;


long long n, k;

int main() {
	FastIO;
	cin >> n >> k;

	double E = (n + 1.0) / 2;

	if (k == 1) {
		cout << E;
		return 0;
	}
	if (n == 1) {
		cout << 1;
		return 0;
	}
	for (int i = 2; i <= k; i++) {
		long long u = (int)E;
		E = (u * E + (u + 1 + n) * 0.5 * (n - u)) / n;
	}
	cout << fixed << setprecision(10) << E;
}