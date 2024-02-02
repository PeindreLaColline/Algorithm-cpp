#include <iostream>
#include <queue>

using namespace std;

int main() {
	int N;
	cin >> N;
	priority_queue<int, vector<int>, greater<int> > Q;

	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		Q.push(tmp);
	}

	int ans = 0;
	for (int i = N; i > 0; i--) {
		ans += (Q.top() * i);
		Q.pop();
	}

	cout << ans;
}