#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
#include <unordered_set>
using namespace std;


int N, M;
unordered_set<int> S;

int main() {

	int N;
	cin >> N;
	while (N-- > 0) {
		int q;
		cin >> q;
		S.insert(q);
	}

	int M;
	cin >> M;
	while (M-- > 0) {
		int q;
		cin >> q;
		cout << (S.find(q) == S.end() ? 0 : 1) << "\n";

	}

}