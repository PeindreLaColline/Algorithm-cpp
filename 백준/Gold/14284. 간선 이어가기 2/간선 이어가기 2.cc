/*
백준 14284
골드5
다익스트라
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 98765432

int n, m;
vector<vector<pair<int, int>>> edge;
vector<int> dst;
int s, e;

int ans = INF;

void dijkstra() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	//<weight, index>

	pq.push({ 0, s });
	dst[s] = 0;

	int cind, cwei, nind, nwei;
	while (!pq.empty()) {
		cind = pq.top().second;
		cwei = pq.top().first;
		pq.pop();

		for (int i = 0; i < edge[cind].size(); i++) {
			nind = edge[cind][i].second;
			nwei = edge[cind][i].first;

			if (dst[nind] > dst[cind] + nwei) {
				dst[nind] = dst[cind] + nwei;
				pq.push({ nwei, nind });
			}

			if (nind == e) {
				if (ans > dst[e]) ans = dst[e];
				continue;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	edge.resize(n+1);
	dst.resize(n + 1, INF);

	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		edge[a].push_back({ c, b });
		edge[b].push_back({ c, a });
	}

	cin >> s >> e;
	dijkstra();

	cout << ans;
}
