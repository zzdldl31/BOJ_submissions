#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int N;

int ances[100];
double x[100];
double y[100];
priority_queue<pair<double, pair<int, int> > > pq;
double min_cost = 0;
int vcnt;

int find_ances(int v) {
	int ans = v;
	int ans2 = v;

	while (ances[ans] != -1)
		ans = ances[ans];

	int before;
	while (ances[ans2] != -1) {
		before = ans2;
		ans2 = ances[ans2];
		ances[before] = ans;
	}
	return ans;
}

void KK() {
	pair<double, pair<int, int> > minel;
	while (pq.size() > 0 && vcnt < N - 1) {
		minel = pq.top();
		pq.pop();

		int a, b;
		a = minel.second.first;
		b = minel.second.second;
		a = find_ances(a);
		b = find_ances(b);
		if (a != b) {
			vcnt++;
			ances[b] = a;
			min_cost += -minel.first;
		}
	}

}

void reset_ances() {
	for (int i = 0; i < N; i++)
		ances[i] = -1;
}

double dist(int a, int b) {
	
	return sqrt((x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]));
}

int main() {
	cin >> N;

	double X, Y;
	for (int i = 0; i < N; i++) {
		cin >> X >> Y;
		x[i] = X; y[i] = Y;
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++)
			pq.push(make_pair(-dist(i, j), make_pair(i, j)));
	}

	reset_ances();
	KK();
	cout << min_cost;


	return 0;
}
