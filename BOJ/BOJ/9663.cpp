#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ABS(X) ((X)>=0?(X):-(X))
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <string>
typedef long long ll;
using namespace std;

int N, M, V;
int T = 1;

int row[15];


bool check(int r) {
	int c = row[r];
	if (c >= N) return false;
	if (r == 0) return true;

	for (int i = 0; i < r; i++) {
		int j = row[i];

		if (c == j) return false;
		if (ABS(r - i) == ABS(c - j)) return false;

	}

	return true;
}

int main() {
	FastIO;

	while (T-- > 0) {

		cin >> N;

		int cnt = 0;

		int piv = 0;
		row[piv] = -1;
		while (piv>=0) {
			row[piv]++;

			if (row[piv] >= N){
				piv--;
				continue;
			}
			if (check(piv)) {
				if (piv == N - 1) {
					cnt++;
					piv--;
				}
				else {
					piv++;
					row[piv] = -1;
				}
			}

		}
		cout << cnt;
	}


	return 0;
}