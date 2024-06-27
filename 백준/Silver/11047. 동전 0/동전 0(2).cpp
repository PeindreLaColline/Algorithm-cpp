*
  previous code was better in my opinion
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> coin;
int n, k;

int ans = 100000001;

void greedy(int num, int cnt, int idx) {
	if (num == 0) {
		if (ans > cnt) ans = cnt;
		return;
	}
	else if (num < 0) {
		return;
	}
	if (idx < 0) return;
	if (ans < cnt) return;
	greedy(num % coin[idx], cnt + num / coin[idx], idx-1);
	greedy(num, cnt, idx - 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	coin.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}
	for (int i = n - 1; i >= 0; i--) {
		if (coin[i] <= k) {
			greedy(k, 0, i);
			break;
		}
	}
	cout << ans;
}
