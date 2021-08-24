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

int board[100][100];
bool norm[100][100];
bool colb[100][100];

int DFS(int x, int y, int color, bool isblind) {
	if (x < 0 || x >= N) return 0;
	if (y < 0 || y >= N) return 0;
	if (color != -1) {
		if (!isblind){
			if(board[x][y] != color) return 0;
		}
		else if (board[x][y] > 0 ^ color > 0) {
			return 0;
		}
	}
	auto arr = isblind ? colb : norm;
	if (arr[x][y]) return 0;
	arr[x][y] = true;

	DFS(x + 1, y, board[x][y], isblind);
	DFS(x - 1, y, board[x][y], isblind);
	DFS(x, y + 1, board[x][y], isblind);
	DFS(x, y - 1, board[x][y], isblind);

	return color == -1 ? 1 : 0;
}

int main() {
	FastIO;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < N; j++) {
			if (str.at(j) == 'R')
				board[i][j] = 1;
			if (str.at(j) == 'G')
				board[i][j] = 2;
			if (str.at(j) == 'B')
				board[i][j] = 0;
		}
	}

	while (T-- > 0) {
		int c1 = 0, c2 = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				c1 += DFS(i, j, -1, false);
				c2 += DFS(i, j, -1, true);
			}
		}

		cout << c1 << " " << c2;
	}


	return 0;
}