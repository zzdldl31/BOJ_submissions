#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD 1000000000
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

long long all[120][10];
long long no0[120][10];
long long no9[120][10];
long long both[120][10];
long long ans[120];

int main() {
	FastIO;


	while (T-- > 0) {
		
		cin >> N;

		all[1][0] = 0;
		for (int j = 1; j <= 9; j++) {
			all[1][j] = 1;
			no0[1][j] = 1;
			if (j != 9)
				no9[1][j] = both[1][j] = 1;
		}

		for (int i = 2; i <= N; i++) {

			for (int j = 0; j <= 9; j++) {
				if (j != 0)
					all[i][j] += all[i - 1][j - 1];
				if (j != 9)
					all[i][j] += all[i - 1][j + 1];
				all[i][j] %= MOD;
			}

			for (int j = 1; j <= 9; j++) {
				if (j != 1)
					no0[i][j] += no0[i - 1][j - 1];
				if (j != 9)
					no0[i][j] += no0[i - 1][j + 1];
				no0[i][j] %= MOD;
			}

			for (int j = 0; j <= 8; j++) {
				if (j != 0)
					no9[i][j] += no9[i - 1][j - 1];
				if (j != 8)
					no9[i][j] += no9[i - 1][j + 1];
				no9[i][j] %= MOD;
			}

			for (int j = 1; j <= 8; j++) {
				if (j != 1)
					both[i][j] += both[i - 1][j - 1];
				if (j != 8)
					both[i][j] += both[i - 1][j + 1];
				both[i][j] %= MOD;
			}

		}

		for (int i = 1; i <= N; i++) {
			for (int j = 0; j <= 9; j++) {
				ans[i] += all[i][j];
				ans[i] -= no0[i][j];
				ans[i] -= no9[i][j];
				ans[i] += both[i][j];
				ans[i] %= MOD;
				ans[i] = (ans[i] + MOD) % MOD;
			}

		}

		cout << ans[N];
	}


	return 0;
}