#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int k, num;
vector<int> hist;
vector<vector<int>> map;
int idx = 0;

void lmr(int dep) {
	if (dep == k) {
		map[dep].push_back(hist[idx]);
		idx++;
		return;
	}
	if (idx >= num) return;
	lmr(dep + 1);
	if (idx >= num) return;
	map[dep].push_back(hist[idx]);
	idx++;
	if (idx >= num) return;
	lmr(dep + 1);
}

int main() {
	cin >> k;
	num = pow(2, k)-1;
	hist.resize(num);
	map.resize(k+1);

	for (int i = 0; i < num; i++) {
		cin >> hist[i];
	}

	lmr(0);
	for (int i = 1; i < map.size(); i++) {
		for (int j = 0; j < map[i].size(); j++) {
			cout << map[i][j]<<" ";
		}
		cout << endl;
	}
}