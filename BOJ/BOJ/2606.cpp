#include <iostream>
#include <vector>
using namespace std;

int N,C;
vector<int> conn[120];
bool virus[120];
int vcnt;

void mark(int n) {
	if (virus[n])
		return;
	virus[n] = true;
	vcnt ++;
}

void DFS(int n) {
	for (int neighbor : conn[n]) {
		if (!virus[neighbor]) {
			mark(neighbor);
			DFS(neighbor);
		}
	}
}



int main() {

	cin >> N >> C;
	while (C-- > 0) {
		int q, w;
		cin >> q >> w;
		conn[q].push_back(w);
		conn[w].push_back(q);
	}
	
	for (int i = 1; i <= N; i++)
		virus[i] = false;
	mark(1);
	DFS(1);

	cout << vcnt-1;
}

