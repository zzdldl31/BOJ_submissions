#include <iostream>
using namespace std;

int R, C;


int main() {
	cin >> R >> C;
	int Rmax=0, Cmax = 0;

	for (int i = 0; i < R; i++) {
		int r;
		cin >> r;
		Rmax = Rmax >= r ? Rmax : r;
	}

	for (int i = 0; i < C; i++) {
		int c;
		cin >> c;
		Cmax = Cmax >= c ? Cmax : c;
	}

	if (Rmax == Cmax)
		cout << "possible";
	else cout << "impossible";
}