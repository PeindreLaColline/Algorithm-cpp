#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> card;
vector<int> visited;
int ans = 0;

void get_card(int cnt, int val) {
	if (cnt == 3) {
		if (ans < val && val <= m) ans = val;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		get_card(cnt + 1, val + card[i]);
		visited[i] = false;
	}
}

int main() {	
	cin >> n >> m;
	card.resize(n);
	visited.resize(n, false);

	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}

	get_card(0, 0);
	cout << ans;
}