#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
using namespace std;

int T;
int A, B;

int main() {
	FastIO

	cin >> T;
	while (T-- > 0) {
		cin >> A >> B;
		cout << A + B << "\n";
	}

}