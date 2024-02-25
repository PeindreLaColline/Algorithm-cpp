#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

#define INF 987654321

int main() {
	int m, n; //m가로 n세로
	cin >> m >> n;
	
	string tmp;
	vector<vector<int>> board(n);
	vector<vector<int>> weight(n);
	vector<vector<bool>> visited(n);
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		for (int j = 0; j < m; j++) {
			board[i].push_back(int(tmp[j])-48);
			weight[i].push_back(INF);
			visited[i].push_back(false);
		}
	}
	weight[0][0] = 0;

	/*
	auto comparator = [](const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
		return greater<int>()(a.first, b.first);
	};
	priority_queue < pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	*/

	queue < pair<int, pair<int, int>>> pq;

	vector<pair<int, int>> direction; //x,y
	direction.push_back({ 1, 0 });		//right
	direction.push_back({ 0, 1 });		//down
	direction.push_back({ -1, 0 });		//left
	direction.push_back({ 0, -1 });		//up

	int ans = INF;

	pq.push({ 0, { 0, 0 } }); //{weight, {x, y}}
	pair<int, int> cind, nind;
	int cwei, nwei;
	while (!pq.empty()) {
		/*
		cind = pq.top().second;
		cwei = pq.top().first;
		*/

		cind = pq.front().second;
		cwei = pq.front().first;
		pq.pop();

		//if (visited[cind.second][cind.first] == true) continue;
		//visited[cind.second][cind.first] == true;

		for (int i = 0; i < 4; i++) {
			nind = {cind.first + direction[i].first, cind.second + direction[i].second};
			if ((nind.first < 0) || (nind.first >= m) || (nind.second < 0) || (nind.second >= n)) continue;
			nwei = cwei + board[nind.second][nind.first];

			/*
			if ((nind.first == m-1) && (nind.second == n-1)) {
				if (nwei < ans) {
					ans = nwei;
					weight[nind.second][nind.first] = nwei;
				}
				continue;
			}
			*/
			/*
				if (weight[nind.second][nind.first] > nwei) {
				weight[nind.second][nind.first] = nwei;
				
				pq.push({ nwei, nind });
				visited[nind.second][nind.first] = false;
			} 
			*/

			if (board[nind.second][nind.first] == 1) {
				if (weight[nind.second][nind.first] > weight[cind.second][cind.first] + 1) {
					weight[nind.second][nind.first] = weight[cind.second][cind.first] + 1;
					pq.push({ weight[nind.second][nind.first], nind });
				}
			}
			else if (board[nind.second][nind.first] == 0) {
				if (weight[nind.second][nind.first] > weight[cind.second][cind.first] ) {
					weight[nind.second][nind.first] = weight[cind.second][cind.first];
					pq.push({ weight[nind.second][nind.first], nind });
				}
			}
		}
	}
	
	cout << weight[n - 1][m - 1];

}