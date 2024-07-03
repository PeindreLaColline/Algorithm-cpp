#include <iostream>
#include <vector>
using namespace std;


int n, m, k;
vector<int> price;
vector<int> parent;
vector<int> get_ans;

void make() {
	parent.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
}

int find(int a) {
	if (parent[a] == a) return a;
	return parent[a] = find(parent[a]);
}

void unite(int a, int b) {
	int ra = find(a);
	int rb = find(b);
	if (ra == rb) return;
	parent[rb] = ra;
	return;
}

int main() {
	cin >> n >> m >> k;
	price.resize(n+1);

	for (int i = 1; i < n+1; i++) {
		cin >> price[i];
	}

	make();
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		unite(a, b);
	}

	for (int i = 1; i <= n; i++) {
		find(i);
	}

	get_ans.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		if (get_ans[parent[i]] == 0) {
			get_ans[parent[i]] = price[i];
		}
		else if (get_ans[parent[i]] > price[i]) get_ans[parent[i]] = price[i];
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (get_ans[i] > 0) ans += get_ans[i];
	}

	if (ans <= k) cout << ans;
	else cout << "Oh no";
}