#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
typedef long long ll;
using namespace std;

int N, M, H;
int T = 1;
int board[100][100][100];
queue<pair<pair<int, int> , pair<int, int> > > riped; //x,y,z,d
int tcnt = 0;
int curmax = 0;

void BFS() {
	while (riped.size() > 0) {
		pair<pair<int, int>, pair<int, int> > ele = riped.front();
		riped.pop();
		int x, y, z, d;
		x = ele.first.first;
		y = ele.first.second;
		z = ele.second.first;
		d = ele.second.second;
		if (x < 0 || x >= M) continue;
		if (y < 0 || y >= N) continue;
		if (z < 0 || z >= H) continue;
		if (board[x][y][z] != 0) continue;
		board[x][y][z] = 1;
		tcnt++;
		curmax = max(curmax, d);
		riped.push({ {x + 1,y},{z,d + 1} });
		riped.push({ {x - 1,y},{z,d + 1} });
		riped.push({ {x,y + 1},{z,d + 1} });
		riped.push({ {x,y - 1},{z,d + 1} });
		riped.push({ {x,y},{z + 1,d + 1} });
		riped.push({ {x,y},{z - 1,d + 1} });
	}

}

int main() {
	cin >> M >> N >> H;
	for (int k = 0; k < H; k++) {
		for (int j = 0; j < N; j++) {
			for (int i = 0; i < M; i++) {
				int q;
				cin >> q;
				if (q == -1) {
					tcnt++;
					board[i][j][k] = q;
				}
				if (q == 1) riped.push({ {i,j},{k,0} });
			}
		}
	}

	while (T-- > 0) {

		BFS();
		if (tcnt != M * N * H)
			cout << "-1";
		else {
			cout << curmax;
		}

	}


	return 0;
}