#include <iostream>
#include <string>
using namespace std;
int T;

int main() {
	cin >> T;
	while (T-- > 0) {
		int R;
		string S;
		cin >> R >> S;
		for (char c : S) {
			for (int i = 0; i < R; i++)
				cout << c;
		}
		cout << endl;
	}
}
