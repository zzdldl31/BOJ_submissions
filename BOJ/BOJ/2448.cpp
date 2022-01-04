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

bool pic[4000][8000];

void draw(int size, int x, int y) {
	if (size == 3) {
		pic[x][y + 2] = true;
		pic[x + 1][y + 1] = true;
		pic[x + 1][y + 3] = true;
		pic[x + 2][y] = true;
		pic[x + 2][y + 1] = true;
		pic[x + 2][y + 2] = true;
		pic[x + 2][y + 3] = true;
		pic[x + 2][y + 4] = true;
	}
	else {
		draw(size / 2, x + 0, y + size / 2);
		draw(size / 2, x + size / 2, y + 0);
		draw(size / 2, x + size / 2, y + size);
		draw(size / 2, x + size / 2, y + size);
	}

}


int main() {
	FastIO;

	cin >> N;


	draw(N, 0, 0);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2 * N; j++) {
			cout << (pic[i][j] ? "*" : " ");
		}
		cout << "\n";
	}


	return 0;
}