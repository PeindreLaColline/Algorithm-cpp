#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
vector<int> indegree;
vector<vector<int>> node;

void bfs() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) q.push(i);
	}

	int num, tmp;
	while (!q.empty()) {
		num = q.front();
		q.pop();
		cout << num<<" ";
		for (int i = 0; i < node[num].size(); i++) {
			tmp = node[num][i];
			if (--indegree[tmp] == 0) q.push(tmp);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	node.resize(n + 1);
	indegree.resize(n + 1, 0);

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		node[a].push_back(b);
		indegree[b]++;
	}

	bfs();
}