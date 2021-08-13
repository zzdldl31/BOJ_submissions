#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
using namespace std;
#define MOD 10007

int comb[60][60];
int N;


void set_comb() {
	for (int i = 0; i <= 52; i++) {
		comb[i][0] = 1;
		comb[i][1] = i;
	}
	for (int j = 2; j <= 52; j++) {
		comb[j][j] = 1;
		for (int i = j + 1; i <= 52; i++) {
			comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
		}
	}
}

int main() {
	set_comb();
	cin >> N;
	int k = N / 4;
	int ways = 0;
	int sgn = 1;
	for (int i = 1; i <= k; i++) {
		int add = comb[13][i] * comb[52 - 4 * i][N - 4 * i];
		add %= MOD;
		add *= sgn;
		add += MOD;
		add %= MOD;
		ways = (ways + add) % MOD;
		sgn = -sgn;
	}
	cout << ways;

}