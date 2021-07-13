#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
using namespace std;

int N;
int mem[10020];

int main() {
	FastIO;

	cin >> N;
	while (N-- > 0) {
		int q;
		cin >> q;
		mem[q]++;
	}

	for (int i = 1; i <= 10000; i++) {
		for (int j = 0; j < mem[i]; j++)
			cout << i << "\n";

	}



}