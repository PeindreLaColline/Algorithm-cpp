#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> v;
vector<bool> visited;

int ans = 0;

void dfs(int cur) {
	int next;
	for (int i = 0; i < v[cur].size(); i++) {
		next = v[cur][i];
		if (visited[next] == true) continue;
		else {
			visited[next] = true;
			ans++;
			dfs(next);
		}
	}
}

int main() {
	int cn;
	cin >> n >> cn;
	v.resize(n+1);
	visited.resize(n + 1, false);

	int a, b;
	while (cn >= 1) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		cn--;
	}

	visited[1] = true;
	dfs(1);
	cout << ans;
}