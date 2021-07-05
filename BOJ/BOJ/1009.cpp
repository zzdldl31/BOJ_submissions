#include <iostream>
using namespace std;

int T, A, B;

int exptable[10][4] = {
	{10,10,10,10},
	{1,1,1,1},
	{6,2,4,8},
	{1,3,9,7},
	{6,4,6,4},
	{5,5,5,5},
	{6,6,6,6},
	{1,7,9,3},
	{6,8,4,2},
	{1,9,1,9}
};

int main() {
	cin >> T;
	while (T-- > 0) {
		cin >> A >> B;
		cout << exptable[A%10][B%4] << endl;
	}

}