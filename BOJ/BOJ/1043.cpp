#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
#include <vector>
using namespace std;

vector<int> conn[160];
vector<int> truth;
int val[160];

int N, M;


void DFS(int v) {
	if (val[v] == 1) return;
	val[v] = 1;
	for (int c : conn[v])
		DFS(c);
}

int main() {
	cin >> N >> M;
	int t, tr, n;
	cin >> t;
	while (t-- > 0) {
		cin >> tr;
		truth.push_back(tr);
	}
	for (int i = 1; i <= M; i++) {
		cin >> n;
		while (n-- > 0) {
			cin >> tr;
			conn[100 + i].push_back(tr);
			conn[tr].push_back(100 + i);
		}
	}

	for (int trueknower : truth) {
		DFS(trueknower);
	}

	int cnt = 0;
	for (int i = 1; i <= M; i++) {
		if (val[100 + i] == 0)
			cnt++;
	}
	
	cout << cnt;

	return 0;
}
