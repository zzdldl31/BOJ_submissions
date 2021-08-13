#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
#include <vector>
using namespace std;


int V;
vector<int> conn[100020];
vector<int> dist[100020];
//vector<pair<int, int> >E[100020];

int dirMax[100020];
int localMax[100020];
//vector<int> dirMax;
//vector<int> localMax;

int cand, temp;
void Dig(int ind, int root) {
	int max1 = 0;
	int max2 = 0;
	if (conn[ind].size() == 1 && root == conn[ind][0]) return;

	for (int i = 0; i < conn[ind].size(); i++) {
		int child = conn[ind][i];
		if (child == root)
			continue;

		Dig(child, ind);

		cand = dirMax[child] + dist[ind][i];
		if (cand > max2) {
			if (cand > max1) {
				max2 = max1;
				max1 = cand;
			}
			else {
				max2 = cand;
			}
		}

		if (localMax[child] > localMax[ind]) localMax[ind] = localMax[child];

	}

	dirMax[ind] = max1;
	localMax[ind] = (localMax[ind] > max1 + max2) ? localMax[ind] : (max1 + max2);
}



int main() {
	cin >> V;

	for (int i = 1; i <= V; i++) {
		int q, w, v;
		cin >> v;
		cin >> w;
		while (w != -1) {
			cin >> q;

			//E[v].push_back(make_pair(w, q));
			conn[v].push_back(w);
			dist[v].push_back(q);
			cin >> w;
		}
	}

	Dig(1, -1);
	cout << localMax[1];

}

