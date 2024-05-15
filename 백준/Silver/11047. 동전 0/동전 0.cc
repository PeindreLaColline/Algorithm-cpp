#include <iostream>
#include <vector>
using namespace std;

vector<int> coin;
int n, k;
int ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	ans = k + 1;

	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (tmp > k) continue;
		else coin.push_back(tmp);
	}

	ans = 0;
	n = coin.size() - 1;
	for (int i = n; i >= 0; i--) {
		ans += k / coin[i];
		k %= coin[i];
		if (k <= 0) break;
	}

	cout << ans;
}