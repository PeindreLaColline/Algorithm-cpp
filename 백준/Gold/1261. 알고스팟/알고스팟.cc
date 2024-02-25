#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

#define INF 987654321

struct compare {
	bool operator()(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
		return a.first > b.first;
	}
};

int main() {
	int m, n; //m가로 n세로
	cin >> m >> n;
	
	string tmp;
	vector<vector<int>> board(n);
	vector<vector<int>> weight(n);
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		for (int j = 0; j < m; j++) {
			board[i].push_back(int(tmp[j])-48);
			weight[i].push_back(INF);
		}
	}
	weight[0][0] = 0;

	priority_queue < pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, compare> pq;
	//{weight, { x, y }}

	vector<pair<int, int>> direction;	//x, y moving
	direction.push_back({ 1, 0 });		//right
	direction.push_back({ 0, 1 });		//down
	direction.push_back({ -1, 0 });		//left
	direction.push_back({ 0, -1 });		//up

	pair<int, int> cind, nind;
	int cwei, nwei;

	pq.push({ 0, { 0, 0 } }); //{weight, {x, y}}
	while (!pq.empty()) {
		cind = pq.top().second;
		cwei = pq.top().first;
		pq.pop();

		for (int i = 0; i < 4; i++) {
			nind = {cind.first + direction[i].first, cind.second + direction[i].second};
			if ((nind.first < 0) || (nind.first >= m) || (nind.second < 0) || (nind.second >= n)) continue;
			nwei = cwei + board[nind.second][nind.first];

			if (weight[nind.second][nind.first] > nwei) {
				weight[nind.second][nind.first] = nwei;
				pq.push({ nwei, nind });
			} 
		}
	}
	cout << weight[n - 1][m - 1];
}