/*
2847 게임을 만든 동준이
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> num;

int main() {
	int n;
	cin >> n;
	num.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	int ans = 0;
	for (int i = n - 1; i > 0; i--) {
		if (num[i - 1] >= num[i]) {
			ans += (num[i-1] - num[i] + 1);
			num[i - 1] = num[i] - 1;
		}
	}

	cout << ans;
}