#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <string>
typedef long long ll;
using namespace std;

long long x1, x2, x3, x4, yy1, y2, y3, y4;
int T = 1;




int main() {
	FastIO;
	cout.precision(11);
	while (T-- > 0) {
		cin >> x1 >> yy1 >> x2 >> y2;
		cin >> x3 >> y3 >> x4 >> y4;

		long long x21, x31, x43, y21, y31, y43;

		x21 = x2 - x1;
		x31 = x3 - x1;
		x43 = x4 - x3;
		y21 = y2 - yy1;
		y31 = y3 - yy1;
		y43 = y4 - y3;

		long long det = x43 * y21 - x21 * y43;



		bool meet = false;
		bool uniq = false;
		double x, y;

		if (det == 0) {
			if (x21 == 0 && y21 == 0 && x43 == 0 && y43 == 0) {
				if (x1 == x3 && yy1 == y3) {
					meet = true;
					uniq = true;
					x = x1;
					y = yy1;
				}
				else {
					meet = false;
				}
			}
			else {
				if (x43 == 0 && y43 == 0) {
					long long q;

					q = x1;
					x1 = x3;
					x3 = q;

					q = yy1;
					yy1 = y3;
					y3 = q;

					q = x2;
					x2 = x4;
					x4 = q;

					q = y2;
					y2 = y4;
					y4 = q;

					x21 = x2 - x1;
					x31 = x3 - x1;
					x43 = x4 - x3;
					y21 = y2 - yy1;
					y31 = y3 - yy1;
					y43 = y4 - y3;
				}

				if (x43 * y31 - y43 * x31 != 0) {
					meet = false;
				}
				else {
					double t, s;
					if (y43 == 0) {
						t = -x31 * 1.0 / x43;
						s = (x21 - x31) * 1.0 / x43;
					}
					else {
						t = -y31 * 1.0 / y43;
						s = (y21 - y31) * 1.0 / y43;
					}

					if (t > s) {
						double q;
						q = t;
						t = s;
						s = q;
					}

					if (s < 0 || t > 1) {
						meet = false;
					}
					else {
						double sup=1, inf=0;
						if (s < 1) sup = s;
						if (t > 0) inf = t;

						meet = true;
						if (sup == inf) {
							uniq = true;
							x = x3 + sup * x43;
							y = y3 + sup * y43;
						}
						else {
							uniq = false;
						}
					}
				}

			}
		}
		else {
			double t, s;
			t = (x43 * y31 - x31 * y43) * 1.0 / det;
			s = (x21 * y31 - x31 * y21) * 1.0 / det;

			if (t < 0 || t>1 || s < 0 || s>1) {
				meet = false;
			}
			else {
				meet = true;
				uniq = true;
				x = x1 + t * x21;
				y = yy1 + t * y21;
			}
		}


		if (meet) {
			cout << "1\n";
			if (uniq) {
				cout << x << " " << y << "\n";
			}
		}
		else {
			cout << "0\n";
		}


	}
	return 0;
}