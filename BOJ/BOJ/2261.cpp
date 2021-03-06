#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define HASH_SIZE 5200000
#include <iostream>
#include <vector>
#include <unordered_set>
#include <utility>
#include <math.h>
using namespace std;

unsigned int Hfunc(int x, int y) {
	long long longbit = (x * (long long)73856093) ^ (y * (long long)19349663);
	longbit %= HASH_SIZE;
	unsigned int h = ((unsigned int)longbit) % HASH_SIZE;

	return h;
}

struct pair_hash {
	template <class T1, class T2>
	size_t operator()(pair<T1, T2> const& pair) const {

		//size_t h1 = hash<T1>()(pair.first);
		//size_t h2 = hash<T2>()(pair.second);
		size_t hh = Hfunc(pair.first, pair.second);
		return hh;
	}
};

int N;
unordered_set<int> Si;
unordered_set<pair<int,int>, pair_hash> Si;
pair<int, int> p[100000];
int curmin = -1;


int Neighbor[HASH_SIZE];
vector<int> Mesh[HASH_SIZE];
int hashindex[100000];
float cellsize;


int dist(pair<int, int> p1, pair<int, int> p2) {
	int dsq = (p1.first - p2.first) * (p1.first - p2.first);
	dsq += (p1.second - p2.second) * (p1.second - p2.second);
	return dsq;
}

int d_i(int i) {

	int mind = -1;
	for (auto j : Si) {
		int d = dist(p[i], p[j]);
		if (d == 0) continue;
		if (mind<0 || mind>d)
			mind = d;
	}
	return mind;
}



void Nsearch(int mesh) {
	if (mesh <= 1) return;
	cellsize = sqrt((float)mesh);

	for (int i = 0; i < N; i++) {
		int hx, hy, x, y;
		unsigned int h;
		hx = (int)(p[i].first / cellsize);
		hy = (int)(p[i].second / cellsize);

		int dx[] = { -1,0,1,-1,0,1,-1,0,1 };
		int dy[] = { -1,-1,-1,0,0,0,1,1,1 };
		for (int j = 0; j < 9; j++) {
			x = hx + dx[j];
			y = hy + dy[j];
			h = Hfunc(x, y);

			Mesh[h].push_back(i);
			if (j == 4)
				hashindex[i] = h;
		}
	}
}

void meshhash(int mesh) {
	if (mesh <= 1) return;
	cellsize = sqrt((float)mesh)/3.0f;

	for (auto i : Si) {
		int hx, hy, x, y;
		unsigned int h;
		hx = (int)(p[i].first / cellsize);
		hy = (int)(p[i].second / cellsize);

		int dx[] = { -1,0,1,-1,0,1,-1,0,1 };
		int dy[] = { -1,-1,-1,0,0,0,1,1,1 };
		for (int j = 0; j < 9; j++) {
			x = hx + dx[j];
			y = hy + dy[j];
			h = Hfunc(x, y);

			Neighbor[h]++;
			if (j == 4)
				hashindex[i] = h;
		}
	}
}
void remove_alone() {
	vector<int> removelist;
	for (auto i : Si) {
		if (Neighbor[hashindex[i]] == 1)
			removelist.push_back(i);
	}
	if (removelist.empty())
		removelist.push_back(*Si.begin());

	for (auto i : removelist) {
		Si.erase(i);
	}
}

void clearmesh() {
	fill(Neighbor, Neighbor+N, 0);
}
void clear_mv() {
	for (int i = 0; i < N; i++) {
		int x, y;
		x = p[i].first; y = p[i].second;
		int hh = Hfunc(x, y);
		Mesh[hh].clear();
	}
}


void Sieve() {

	do {
		//pair<int, int> x0 = p[*Si.begin()];

		int mind = d_i(0);

		curmin = (curmin<0 || curmin>mind) ? mind : curmin;
		if (curmin>=0 && curmin <= 1) {
			return;
		}

		meshhash(curmin);
		remove_alone();
		clearmesh();
	} while (Si.size() > 1);
	
	Nsearch(curmin);
	for (int i = 0; i < N; i++) {
		int h = hashindex[i];
		int l = Mesh[h].size();
		for (int j = 0; j < l; j++) {
			int d = dist(p[i], p[Mesh[h][j]]);
			if (d == 0) continue;
			if (curmin<0 || curmin>d) curmin = d;
		}
	}

}


int main() {
	FastIO;
	cin >> N;
	
	bool dup = false;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;

		p[i] = make_pair(x, y);
		int hh = Hfunc(x, y);
		
		if (!dup && Mesh[hh].size() > 0) {
			for (auto j : Mesh[hh]) {
				if (p[i].first == p[j].first && p[i].second == p[j].second){
					dup = true;
					break;
				}
			}
		}
		else {
			Mesh[hh].push_back(i);
			Si.insert(i);
		}
	}
	if (dup) {
		cout << 0;
		return 0;
	}

	clear_mv();
	//clearmesh();
	Sieve();
	cout << curmin;

	return 0;
}