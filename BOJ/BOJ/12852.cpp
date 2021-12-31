#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
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

int dist[1000020];
int preq[1000020];


void seek(int n) {
	if (n <= 1) return;
	if (dist[n] != 0) return;


	int mind = -1;
	int pre;
	if (n % 3 == 0){
		seek(n / 3);
		mind = dist[n / 3];
		pre = n / 3;
	}
	if (n % 2 == 0) {
		seek(n / 2);
		if (mind == -1 || dist[n / 2] < mind) {
			mind = dist[n / 2];
			pre = n / 2;
		}
	}
	seek(n - 1);
	if (mind == -1 || dist[n - 1] < mind) {
		mind = dist[n - 1];
		pre = n - 1;
	}

	dist[n] = mind + 1;
	preq[n] = pre;
}

int main() {
	FastIO;

	while (T-- > 0) {

		cin >> N;

		seek(N);

		cout << dist[N] << "\n";
		while (N > 1) {
			cout << N << " ";
			N = preq[N];
		}
		cout << "1";

	}


	return 0;
}