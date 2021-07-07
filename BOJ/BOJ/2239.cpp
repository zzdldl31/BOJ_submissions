#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int board[9][9];
bool given[9][9];


int blankcells[81];
int blank_cnt;
vector<int> conn[81];


void make_connections() {
	for (int r = 0; r < 9; r++)
		for (int c1 = 0; c1 < 9; c1++)
			for (int c2 = c1 + 1; c2 < 9; c2++){
				conn[r * 9 + c2].push_back(r * 9 + c1);
				if(given[r][c2])
					conn[r * 9 + c1].push_back(r * 9 + c2);
			}

	for (int c = 0; c < 9; c++)
		for (int r1 = 0; r1 < 9; r1++)
			for (int r2 = r1 + 1; r2 < 9; r2++) {
				conn[r2 * 9 + c].push_back(r1 * 9 + c);
				if (given[r2][c])
					conn[r1 * 9 + c].push_back(r2 * 9 + c);
			}

	int off_r[] = { 0,0,0,1,1,1,2,2,2 };
	int off_c[] = { 0,1,2,0,1,2,0,1,2 };

	for (int x = 0; x < 9; x += 3)
		for (int y = 0; y < 9; y += 3)
			for (int i = 0; i < 9; i++)
				for (int j = i + 1; j < 9; j++) {
					conn[9 * (x + off_r[j]) + (y + off_c[j])].push_back(9 * (x + off_r[i]) + (y + off_c[i]));
					if (given[x + off_r[j]][y + off_c[j]])
						conn[9 * (x + off_r[i]) + (y + off_c[i])].push_back(9 * (x + off_r[j]) + (y + off_c[j]));

				}

}

void init() {
	make_connections();

	blank_cnt = 0;
	for (int r = 0; r < 9; r++)
		for (int c = 0; c < 9; c++)
			if (!given[r][c])
				blankcells[blank_cnt++] = 9 * r + c;

}

bool dup(int spot) {
	int l = conn[spot].size();
	for (int i = 0; i < l; i++) {
		int comp = conn[spot][i];
		if (board[spot / 9][spot % 9] == board[comp / 9][comp % 9])
			return true;
	}
	return false;
}

bool solve(int pencilmarks) {
	if (pencilmarks >= blank_cnt)
		return true;

	int spot = blankcells[pencilmarks];

	for (int k = 1; k <= 9; k++) {
		
		board[spot / 9][spot % 9] = k;
		if (dup(spot)) continue;

		if (solve(pencilmarks + 1))
			return true;
	}
	board[spot / 9][spot % 9] = 0;
	return false;
}




int main() {
	FastIO;
	
	for (int i = 0; i < 9; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < 9; j++) {
			board[i][j] = str.at(j) - '0';
			if (board[i][j] != 0)
				given[i][j] = true;
		}


	}

	init();

	if (!solve(0))
		cout << "failed" << endl;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {

			cout << board[i][j];
		}
		cout << endl;
	}

}