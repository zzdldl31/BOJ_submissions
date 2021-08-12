#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
using namespace std;

int M, N;
bool isc[1000020];

int main() {
	cin >> M >> N;
	bool first = true;
	for (int i = 2; i <= N; i++) {
		if (!isc[i] && i >= M) {
			if (!first)
				cout << "\n";
			else first = false;
			cout << i;
		}
		for (int j = 2 * i; j <= N; j += i)
			isc[j] = true;

	}


}
