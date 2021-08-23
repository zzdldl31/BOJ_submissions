#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
typedef long long ll;
using namespace std;
#define NMAX 16
#define MASKMAX 65536

int N, M, V;
int T = 1;

int W[NMAX][NMAX];
int mincost[NMAX][MASKMAX];
int target;

void DFS(int v, int o, int path) {
	if (path == target) {
		mincost[v][path] = W[v][o];
		return;
	}
	if (mincost[v][path] != 0)
		return;

	int minnow = -1;

	for (int i = 0; i < N; i++) {
		int next = 1 << i;
		if ((path & next) != 0 || W[v][i] == 0)
			continue;

		DFS(i, o, path | next);
		if (mincost[i][path | next] == 0) continue;
		int cand = mincost[i][path | next] + W[v][i];

		if (minnow == -1 || minnow > cand)
			minnow = cand;
	}

	if (minnow == -1) return;
	
	mincost[v][path] = minnow;

}


int main() {

	cin >> N;
	target = (1 << N) - 1;

	while (T-- > 0) {

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> W[i][j];
			}
		}

		DFS(0, 0, 1);
		cout << mincost[0][1];

	}


	return 0;
}