#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
typedef long long ll;
using namespace std;

int N, M, K;
int T = 1;
bool board[100][100];

int DFS(int x, int y) {
	if (x < 0 || x >= N) return 0;
	if (y < 0 || y >= M) return 0;
	if (board[x][y]) return 0;
	board[x][y] = true;

	return (1 + DFS(x + 1, y) + DFS(x - 1, y) + DFS(x, y + 1) + DFS(x, y - 1));
}


int main() {
	cin >> M >> N >> K;

	while (T-- > 0) {
		while (K-- > 0) {
			int q, w, e, r;
			cin >> q >> w >> e >> r;
			for (int i = q; i < e; i++) {
				for (int j = w; j < r; j++) {
					board[i][j] = true;
				}
			}
		}

		vector<int> clusters;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int c = DFS(i, j);
				if (c != 0)
					clusters.push_back(c);
			}
		}

		sort(clusters.begin(), clusters.end());

		cout << clusters.size() << "\n";
		for (int i = 0; i < clusters.size(); i++)
			cout << clusters[i] << " ";

	}


	return 0;
}