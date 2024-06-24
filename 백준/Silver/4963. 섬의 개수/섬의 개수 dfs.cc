//dfs
#include <iostream>
#include <vector>
using namespace std;

int w, h;
vector<vector<int>> map;
vector<vector<bool>> visited;

int dir[8][8] = { {0, -1}, {1, -1}, {1, 0}, {1, 1},
					{0, 1}, {-1, 1}, {-1, 0}, {-1, -1} };
int island = 0;

void dfs(int x, int y) {
	for (int i = 0; i < 8; i++) {
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		if (nx >= 0 && nx < w && ny >= 0 && ny < h && map[ny][nx] && !visited[ny][nx]) {
			visited[ny][nx] = true;
			dfs(nx, ny);
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

		for (int i = 0;i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == 1 && !visited[i][j]) {
					visited[i][j] = true;
					dfs(j, i);
					island++;
				}
			}
		}
		cout << island << "\n";
	}
}
