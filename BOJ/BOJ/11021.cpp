#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
using namespace std;

int T;


int main() {
	FastIO;

	cin >> T;
	for (int i = 1; i <= T;i++) {
		int q, w;
		cin >> q >> w;

		cout << "Case #" << i << ": " << (q + w) << "\n";
	}
	

}
