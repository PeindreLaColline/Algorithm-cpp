//bfs
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int w, h;
vector<vector<int>> map;
vector<vector<bool>> visited;
queue<pair<int, int>> togo;

int dir[8][8] = { {0, -1}, {1, -1}, {1, 0}, {1, 1},
					{0, 1}, {-1, 1}, {-1, 0}, {-1, -1} };
int island = 0;

int tx, ty;

pair<int, int> discover() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (visited[i][j] == false) {
				if (map[i][j] == 1) {
					tx = j; ty = i;
					return { j, i };
				}
			}
		}
	}
	return { -1, -1 };
}

void bfs() {
	while (true) {
		pair<int, int> tmp = discover();
		if (tmp.first == -1) break;

		togo.push({ tmp.first, tmp.second });
		visited[tmp.second][tmp.first] = true;
		island++;

		while (!togo.empty()) {

			int cx = togo.front().first;
			int cy = togo.front().second;

			togo.pop();

			for (int i = 0; i < 8;i++) {
				int nx = cx + dir[i][0];
				int ny = cy + dir[i][1];

				if (nx < 0 || nx >= w || ny < 0 || ny >= h) {
					continue;
				}
				if (visited[ny][nx]) continue;
				if (map[ny][nx] == 0) continue;
				visited[ny][nx] = true;
				togo.push({ nx,ny });
			}
		}
		
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (true) {
		//init
		map.clear();
		visited.clear();
		island = 0;
		while (!togo.empty()) {
			togo.pop();
		}
		tx = 0; ty = 0;

		cin >> w >> h;
		if (w == 0 && h == 0) break;

		vector<int> tmp(w);
		vector<bool> btmp(w, false);
		for (int i = 0; i < h; i++) {
			map.push_back(tmp);
			visited.push_back(btmp);
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}
		
		bfs();
		cout << island << "\n";

	}
	

}
