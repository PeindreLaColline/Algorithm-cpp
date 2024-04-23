#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 10000001

vector<int> pl(MAX, 0);
vector<int> mi(MAX, 0);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n;

	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (tmp >= 0) pl[tmp]++;
		else mi[abs(tmp)]++;
	}

	cin >> m;
	int target;
	for (int i = 0; i < m; i++) {
		cin >> target;
		if (target >= 0) cout << pl[target] << ' ';
		else cout << mi[abs(target)] << ' ';
	}
}