#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> pq;
priority_queue<int> expect;
int sums[1100000];
int N;
int weights[20];

int main() {
	FastIO;
	cin >> N;
	int t = 1 << N;
	while (t-- > 0) {
		int inp;
		cin >> inp;
		pq.push(-inp);
	}
	/*
	if (pq.top() != 0) {
		cout << "impossible";
		return 0;
	}
	pq.pop();*/
	expect.push(0);

	int kw = 0;
	while (kw < N) {
		bool flag = false;
		if (expect.size() > 0) {
			if (expect.top() == pq.top()) {
				expect.pop(); pq.pop();
				continue;
			}
			else if (expect.top() > pq.top()) {
				cout << "impossible";
				return 0;
			}
			else { flag = true; }
		}



		if (expect.size() == 0 || flag) {
			weights[kw] = pq.top();
			t = 1 << kw;
			for (int i = 0; i < t; i++) {
				sums[t + i] = sums[i] + weights[kw];
				expect.push(sums[t + i]);
			}
			kw++;

		}



	}
	while (expect.size() > 0) {
		if (expect.top() == pq.top()) {
			expect.pop(); pq.pop();
			continue;
		}
		else {
			cout << "impossible";
			return 0;
		}

	}
	for (int i = 0; i < N; i++) {
		cout << (-weights[i]) << endl;
	}

}