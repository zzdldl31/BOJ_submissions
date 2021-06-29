#define MIN(X,Y) ((X)<(Y))?(X):(Y)

#include <iostream>
using namespace std;
int T, N, W;

int upr[10020];
int dwn[10020];


int cache[10020][5][2][2];

int flat(int u, int d, int su,int sd) {
	if (u < su || d < sd)
		return 20000;
	if (u == su && d == sd)
		return 0;
	if (cache[u][u - d + 2][su][sd] != 0)
		return cache[u][u - d + 2][su][sd];
	
	int m1;

	if (u > d) {
		int m2;
		m1 = flat(u - 1, d, su, sd) + 1;
		if (u > su + 1 && upr[u] + upr[u - 1] <= W) {
			m2 = flat(u - 2, d, su, sd) + 1;
			m1= MIN(m1, m2);
		}
	}
	else if (u < d) {
		int m2;
		m1 = flat(u, d - 1, su, sd) + 1;
		if (d > sd + 1 && dwn[d] + dwn[d - 1] <= W) {
			m2 = flat(u, d - 2, su, sd) + 1;
			m1 = MIN(m1, m2);
		}
	}
	else {
		int m2, m3, m4;
		m1 = flat(u - 1, d, su, sd) + 1;
		m2 = flat(u, d - 1, su, sd) + 1;
		m1 = MIN(m1, m2);
		if (upr[u] + dwn[d] <= W) {
			m3 = flat(u - 1, d - 1, su, sd) + 1;
			m1 = MIN(m1, m3);
		}
		if (u >= su + 2 && d >= sd + 2) {
			if (upr[u] + upr[u - 1] <= W && dwn[d] + dwn[d - 1] <= W) {
				m4 = flat(u - 2, d - 2, su, sd) + 2;
				m1 = MIN(m1, m4);
			}
		}
	}
	cache[u][u - d + 2][su][sd] = m1;
	return m1;
}

void resetcache() {
	for(int i=0;i<10020;i++)
		for (int j = 0; j < 5; j++) {
			cache[i][j][0][0] = 0;
			cache[i][j][0][1] = 0;
			cache[i][j][1][0] = 0;
			cache[i][j][1][1] = 0;
		}
}

int main() {
	
	cin >> T;
	while (T-- > 0) {
		resetcache();
		cin >> N >> W;
		for (int i = 1; i <= N; i++)
			cin >> upr[i];
		for (int i = 1; i <= N; i++)
			cin >> dwn[i];

		upr[N + 1] = upr[1];
		dwn[N + 1] = dwn[1];

		int m1, m2, m3, m4;
		m1 = flat(N, N, 0, 0);
		m2 = flat(N + 1, N, 1, 0);
		m3 = flat(N, N + 1, 0, 1);
		m4 = flat(N + 1, N + 1, 1, 1);

		m1 = MIN(m1, m2);
		m1 = MIN(m1, m3);
		m1 = MIN(m1, m4);

		cout << m1 << endl;
	}
}