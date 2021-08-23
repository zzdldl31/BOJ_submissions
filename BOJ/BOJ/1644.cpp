#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
typedef long long ll;
using namespace std;
#define NMAX 4000000

int N, M, V;
int T = 1;

bool isnp[NMAX + 1];
int ways[NMAX + 1];
vector<int> primes;

int main() {
	cin >> N;

	while (T-- > 0) {

		for (int i = 2; i <= N; i++) {
			if (isnp[i])
				continue;
			
			primes.push_back(i);
			for (int j = 2 * i; j <= N; j += i) {
				isnp[j] = true;
			}
		}

		int pn=primes.size();

		for (int i = 0; i < pn; i++) {
			int sum = 0;
			for (int j = i; j < pn; j++) {
				sum += primes[j];
				if (sum > N) break;
				ways[sum]++;
			}
		}

		cout << ways[N];

	}


	return 0;
}