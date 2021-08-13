#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
#include <algorithm>
using namespace std;
#define MOD 1000000007

long long spice[300020];
long long e2[300020];
int N;

void set_e2() {
	e2[0] = 1;
	e2[1] = 2;
	for (int i = 2; i <= 300000; i++)
		e2[i] = (e2[i - 1] << 1) % MOD;

}

int main() {
	FastIO;
	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> spice[i];

	set_e2();
	
	sort(spice+1, spice + N + 1);

	long long cumsum = 0;
	long long coeff;
	for (int k = 1; k <= N; k++) {
		coeff = e2[k - 1] - e2[N - k];
		coeff %= MOD;
		coeff += MOD;
		coeff %= MOD;

		long long sum = coeff * spice[k];
		sum %= MOD;
		cumsum = (cumsum + sum) % MOD;

	}
	cout << cumsum;
}