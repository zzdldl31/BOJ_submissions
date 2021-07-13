#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
#include <string>
using namespace std;

string T, P;
int n, m;

int pre[1000020];
int cnt = 0;
int matchindex[1000020];

void preprocess() {

	for (int i = 0; i < m; i++) {
		if (i == 0) {
			pre[i] = -1;
			continue;
		}

		int p = pre[i - 1];
		if (p < 0) p = 0;

		while (p >= 0) {
			if (P.at(i) == P.at(p)) {

				break;
			}
			p = pre[p];
		}
		pre[i] = p + 1;

	}

}

void count() {

	int pp = -1;
	for (int j = 0; j < n; j++) {
		if (pp < 0) pp = 0;
		while (pp >= 0) {
			if (P.at(pp) == T.at(j)) {
				pp++;
				if (pp == m) {
					pp = pre[pp - 1];
					matchindex[cnt++] = j + 1 - m;
				}
				break;
			}
			else pp = pp > 0 ? pre[pp - 1] : -1;
		}
	}

}


int main() {
	FastIO;
	getline(cin, T);
	getline(cin, P);

	n = T.length();
	m = P.length();


	preprocess();
	count();

	cout << cnt << endl;
	for (int i = 0; i < cnt; i++)
		cout << (matchindex[i] + 1) << " ";
}