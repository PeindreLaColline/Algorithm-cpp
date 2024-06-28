#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	int n;
	cin >> n;

	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		pq.push(tmp);
	}

	int num = 0;
	int ans = 0;
	while (!pq.empty()) {
		num = 0;
		num += pq.top();
		pq.pop();
		if (pq.empty()) {
			break;
		}
		num += pq.top();
		pq.pop();
		pq.push(num);
		ans += num;
	}
	cout << ans;
}