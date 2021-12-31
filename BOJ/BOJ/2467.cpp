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

int potion[100020];


int main() {
	FastIO;


	while (T-- > 0) {

		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> potion[i];
		}

		int inf = 0;
		int sup = N - 1;

		int minsum = potion[inf] + potion[sup];
		int lo = inf;
		int hi = sup;

		if (minsum < 0)
			minsum = -minsum;

		while (inf < sup) {
			bool up = true;

			int sum = potion[inf] + potion[sup];
			if (sum < 0){
				sum = -sum;
				up = false;
			}

			if (sum < minsum) {
				minsum = sum;
				lo = inf;
				hi = sup;
			}

			if (up)
				sup--;
			else
				inf++;

		}

		cout << potion[lo] << " " << potion[hi];
	}

	return 0;
}