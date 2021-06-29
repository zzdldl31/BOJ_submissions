#include <vector>
#include <iostream>
#include <string>
using namespace std;


int N,M, NM;
int board[52][52];

int MAX(int x, int y) {
	if (x <= 0 || y <= 0)
		return -1;
	return x > y ? x : y;
}

int cache[52][52];

int MGL(int x,int y) {
	if (board[x][y] == -1) return 0;
	if (cache[x][y] > 0 || cache[x][y]==-1) return cache[x][y];
	if (cache[x][y] == -2) {
		cache[x][y] = -1;
		return -1;
	}
	cache[x][y] = -2;
	int d = board[x][y];
	int m = 1;
	if (x >= d)
		m = MAX(m, 1 + MGL(x - d, y));
	if (y >= d)
		m = MAX(m, 1 + MGL(x, y - d));
	if (x + d < N)
		m = MAX(m, 1 + MGL(x + d, y));
	if (y + d < M)
		m = MAX(m, 1 + MGL(x, y + d));
	cache[x][y] = m;
	return m;
}


int main() {
	cin >> N >> M;
	NM = N * M;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < M; j++) {
			if (str.at(j) == 'H')
				board[i][j] = -1;
			else board[i][j] = str.at(j) - '0';
		}
	}

	cout << MGL(0, 0);


}
