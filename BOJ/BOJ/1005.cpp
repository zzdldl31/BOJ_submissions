#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int Time[1020];
bool minTime_checked[1020];
vector<int> requirement[1020];

int n, k, w, T;

int cache[1020];
int minTime(int i) {
    if (minTime_checked[i])
        return cache[i];

    int pre = 0;
    int l = requirement[i].size();

    for (int j = 1; j <= l; j++) {
        pre = pre > minTime(requirement[i][j - 1]) ? pre : minTime(requirement[i][j - 1]);
    }
    cache[i] = pre + Time[i];
    minTime_checked[i] = true;

    return cache[i];
}

void reset() {
    for (int i = 1; i <= n; i++) {
        requirement[i].clear();
        minTime_checked[i] = false;
    }
}


int main() {
    cin >> T;
    while (T-- > 0) {
        cin >> n >> k;
        reset();

        for (int i = 1; i <= n; i++)
            cin >> Time[i];
        int a, b;
        while (k-- > 0) {
            cin >> a >> b;
            requirement[b].push_back(a);
        }

        cin >> w;
        cout << minTime(w) << endl;

    }
    return 0;
}