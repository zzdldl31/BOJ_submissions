#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
using namespace std;

bool isc[250000];
int bert[125000];
int N;

void Sieve() {
	for (int i = 2; i < 246913; i++) {
		if (!isc[i]) {
			for (int j = 2 * i; j < 246913; j += i)
				isc[j] = true;

			for (int j = (i + 1) / 2; j < i; j++) {
				if (j > 123456) break;
				bert[j]++;
			}

		}
	
	}

}

void preprocess() {
	Sieve();
}


int main() {
	FastIO;
	preprocess();

	while (true) {
		cin >> N;
		if (N == 0) break;
	
		cout << bert[N] << "\n";
	
	}

}
