#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

string T;
int N, M;



int main() {
	cin >> N >> M;
	cin >> T;
	
	int cnt = 0;
	bool inal = false;
	int IOl = 0;
	for (char c : T) {
		if (!inal && c == 'I') {
			inal = true;
			IOl = 1;
			continue;
		}
		if (inal) {
			if ((IOl % 2 == 0) == (c == 'I')) {
				IOl++;
			}
			else {
				inal = false;
				IOl -= 1;
				IOl /= 2;
				if (IOl >= N)
					cnt += IOl - N + 1;
				if (c == 'I') {
					inal = true;
					IOl = 1;
				}
				else {
					inal = false;
					IOl = 0;

				}
			}
		}
	}
	if (inal) {
		IOl -= 1;
		IOl /= 2;
		if (IOl >= N)
			cnt += IOl - N + 1;

	}

	cout << cnt;

	return 0;
}