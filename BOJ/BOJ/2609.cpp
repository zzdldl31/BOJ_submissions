#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
typedef long long ll;
using namespace std;

int N, M, V;
int T = 1;

int gcd(int a, int b) {
	if (a == 0) return b;
	if (b == 0) return a;
	if (a == 1 || b == 1) return 1;
	if (b < a) return gcd(b, a);
	if (b % a == 0) return a;
	return gcd(b - (b / a) * a, a);
}

int lcm(int a, int b) {

	return (a / gcd(a, b)) * b;
	
}

int main() {
	cin >> N >> M;

	while (T-- > 0) {

		cout << gcd(N, M) << "\n" << lcm(N, M);




	}


	return 0;
}