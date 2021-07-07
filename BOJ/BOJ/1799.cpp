#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
#include <string>
#include <vector>
using namespace std;


int N;
int board[10][10];

int blanks[100];
int blank_cnt;
vector<int> conn[100];

int placed[100];

void init(int parity) {
	blank_cnt = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if ((i + j) % 2 == parity && board[i][j] == 1)
				blanks[blank_cnt++] = i * N + j;
		}

	for (int a = 0; a < blank_cnt; a++){
		conn[a].clear();
		placed[a] = 0;
	}

	for (int a = 0; a < blank_cnt; a++)
		for (int b = a + 1; b < blank_cnt; b++) {
			int ax = blanks[a] / N, ay = blanks[a] % N;
			int bx = blanks[b] / N, by = blanks[b] % N;

			int dx = ax - bx, dy = ay - by;

			if (dx == dy || dx == -dy)
				conn[b].push_back(a);
		}

}

bool dup(int ind) {
	int l = conn[ind].size();
	for (int i = 0; i < l; i++)
		if (placed[conn[ind][i]] == 1)
			return true;

	return false;
}

int solvefrom(int marks) {
	if (marks >= blank_cnt)
		return 0;

	int yes, no;

	if (!dup(marks)) {
		placed[marks] = 1;
		yes = 1 + solvefrom(marks + 1);
		placed[marks] = 0;
	}
	else yes = 0;

	no = solvefrom(marks + 1);


	return yes > no ? yes : no;
}

int main() {
	FastIO;
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	int maxb = 0;
	init(0);
	maxb += solvefrom(0);
	init(1);
	maxb += solvefrom(0);

	cout << maxb;
}