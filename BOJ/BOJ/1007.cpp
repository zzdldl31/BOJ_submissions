#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FIXED_FLOAT(x) fixed <<setprecision(6)<<(x)
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <string>
#include <math.h>
#include <iomanip>
typedef long long ll;
using namespace std;

int N, M, V;
int T = 1;

int x[20];
int y[20];

int main() {
	FastIO;
	cin >> T;

	while (T-- > 0) {
		cin >> N;
		int n = N / 2;

		int X = 0, Y = 0;
		for (int i = 0; i < N; i++) {
			cin >> x[i] >> y[i];
			X += x[i];
			Y += y[i];
		}
		int ones[10];
		for (int i = 0; i < n; i++)
			ones[i] = n + i;

		bool bf = true;
		double minL;
		bool first = true;
		while (bf) {

			long long XX = 0, YY = 0;
			for (int i = 0; i < n; i++) {
				XX += x[ones[i]];
				YY += y[ones[i]];
			}

			double L = sqrt((double)((X - 2 * XX) * (X - 2 * XX) + (Y - 2 * YY) * (Y - 2 * YY)));

			if (first || L < minL) {
				minL = L;
				first = false;
			}

			int piv = ones[n - 1];
			int i;
			for (i = 1; i <= n - 1; i++) {
				if (ones[n - 1 - i] != piv - i)
					break;

			}
			if (ones[n - i] == 0)
				bf = false;
			else {
				ones[n - i]--;
				for (int j = n - i + 1; j < n; j++)
					ones[j] = n + j;
			}
		}
		cout << FIXED_FLOAT(minL) << "\n";

	}


	return 0;
}