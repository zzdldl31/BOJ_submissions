#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<pair<int, int> > conn[20004];
int V, E, S;

bool visited[20004];
int mind[20004];
priority_queue<pair<long long,int> > pq;

int searchMin() {
	int min = -1, ind = -1;

	while (ind == -1 && pq.size()>0) {
		int p = pq.top().second;
		if (!visited[p]) ind = p;
		pq.pop();
	}
	return ind;
}


void DIJK() {
	int rotate = S;
	int w, e, cand;

	while (true) {
		visited[rotate] = true;
		for (int i = 0; i < conn[rotate].size(); i++) {
			w = conn[rotate][i].first;
			if (visited[w])
				continue;
			e = conn[rotate][i].second;
			cand = e + mind[rotate];
			if (mind[w] == 0 || mind[w] > cand){
				mind[w] = cand;
				pq.push(make_pair(-cand, w));
			}
		}

		rotate = searchMin();

		if (rotate == -1)
			break;
	}

}

int main() {
	FastIO;
	cin >> V >> E >> S;

	vector<pair<pair<int, int>, int > > edges;

	int q, w, e;
	for (int i = 0; i < E; i++) {
		cin >> q >> w >> e;
		conn[q].push_back( {w,e} );

	}

	DIJK();

	for (int i = 1; i <= V; i++) {
		if (i != 1)
			cout << "\n";
		if (visited[i])
			cout << mind[i];
		else cout << "INF";

	}

}
