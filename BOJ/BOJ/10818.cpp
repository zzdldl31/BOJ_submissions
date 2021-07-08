#include <iostream>
using namespace std;

int maxn, minn;
int N;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int q;
		cin >> q;
		if (i == 0) {
			maxn = minn = q;
		}
		else {
			if (maxn < q)
				maxn = q;
			if (minn > q)
				minn = q;
		}
	}
	cout << minn << " " << maxn;
}