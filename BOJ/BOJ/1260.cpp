#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
#include <queue>
using namespace std;

int N,M,V;
bool conn[1020][1020];
bool visited[1020];
queue<int> q;

void DFS(int s) {
	cout << s << " ";
	visited[s] = true;

	for (int i = 1; i <= N; i++) {
		if (!visited[i] && conn[s][i])
			DFS(i);
	}
	return;
}

void BFS() {
	if (q.size() == 0) return;
	int s;
	visited[V] = false;
	cout << V << " ";
	while (q.size() > 0) {
		s = q.front();
		q.pop();

		for (int i = 1; i <= N; i++) {
			if (visited[i] && conn[s][i]) {
				cout << i << " ";
				visited[i] = false;
				q.push(i);
			}
		}
	}

}


int main() {
	FastIO;

	cin >> N >> M >> V;
	while (M-- > 0) {
		int A, B;
		cin >> A >> B;
		conn[A][B] = conn[B][A] = true;
	}

	DFS(V);
	cout << "\n";
	q.push(V);
	BFS();
}