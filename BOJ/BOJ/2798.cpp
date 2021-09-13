#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
typedef long long ll;
using namespace std;

int N, M, V;
int T = 1;

int nums[120];

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> nums[i];
	
	int best = -1;

	while (T-- > 0) {
		for (int q = 0; q < N; q++) {
			for (int w = 0; w < N; w++) {
				if (q == w) continue;
				for (int e = 0; e < N; e++) {
					if (q == e || w == e) continue;
					int cand = nums[q] + nums[w] + nums[e];
					if (cand > M) continue;

					if (best < cand) best = cand;
				}

			}

		}

		cout << best;

	}


	return 0;
}