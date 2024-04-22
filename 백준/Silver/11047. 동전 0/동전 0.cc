#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> coin;

int ans = 98765432;

void greedy(int curs, int cn, int idx) {
	if (cn > ans) return;
	if (curs == 0) {
		if (cn < ans) ans = cn;
		return;
	}
	if (idx == -1) return;

	int i = 1;
	while (true) {
		if (curs - coin[idx] * i >= 0) {
			i++;
			continue;
		}
		else {
			break;
		}
	}
	greedy(curs - coin[idx] * (i - 1), cn + i - 1, idx - 1);
}

int main() {	
	cin >> n >> k;
	
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a > k) continue;
		coin.push_back(a);
	}
	n = coin.size();

	greedy(k, 0, n-1);
	cout << ans;
}