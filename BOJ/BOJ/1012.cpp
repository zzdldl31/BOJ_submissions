#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
using namespace std;

int T,M,N,K;
bool B[52][52];
bool visited[52][52];


void DFS(int x, int y) {
	visited[x][y] = true;
	if (x > 0 && B[x - 1][y] && !visited[x - 1][y])
		DFS(x - 1, y);
	if (x < M - 1 && B[x + 1][y] && !visited[x + 1][y])
		DFS(x + 1, y);
	if (y > 0 && B[x][y - 1] && !visited[x][y - 1])
		DFS(x, y - 1);
	if (y < N - 1 && B[x][y + 1] && !visited[x][y + 1])
		DFS(x, y + 1);
}

void resetFarm() {
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++) {
			B[i][j] = false;
			visited[i][j] = false;
		}
}

int main() {
	FastIO;

	cin >> T;
	while (T-- > 0) {
		cin >> M >> N >> K;

		resetFarm();

		while (K-- > 0) {
			int x, y;
			cin >> x >> y;
			B[x][y] = true;
			visited[x][y] = false;
		}

		int cluster = 0;

		for (int i = 0; i < M; i++)
			for (int j = 0; j < N; j++) {
				if (B[i][j] && !visited[i][j]) {
					cluster++;
					DFS(i, j);
				}
			}

		cout << cluster << "\n";
	}

}
