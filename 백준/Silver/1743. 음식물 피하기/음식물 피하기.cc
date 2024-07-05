#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, k;
vector<vector<bool>> map;
vector<vector<bool>> visited;

queue<pair<int, int>> togo;

int dir[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };
int ans = 0;

pair<int, int> find() {
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (!visited[i][j] && map[i][j] == true) return { j, i };
		}
	}
	return { -1, -1 };
}

void bfs() {
	int cx, cy, nx, ny;
	int cur = 0;
	while (!togo.empty()) {
		cx = togo.front().first;
		cy = togo.front().second;
		togo.pop();
		cur++;

		for (int i = 0; i < 4; i++) {
			nx = cx + dir[i][0];
			ny = cy + dir[i][1];
			if (0 < nx && nx < m && 0 < ny && ny < n) {
				if (!visited[ny][nx] && map[ny][nx]) {
					visited[ny][nx] = true;
					togo.push({ nx, ny });
				}
			}
		}
	}
	if (cur > ans) ans = cur;
}

int main() {
	cin >> n >> m >> k;
	n++; m++;

	vector<bool> binit(m, false);
	for (int i = 0; i < n; i++) {
		map.push_back(binit);
		visited.push_back(binit);
	}

	int y, x;
	for (int i = 0; i < k; i++) {
		cin >> y >> x;
		map[y][x] = true;
	}
	
	while (true) {
		togo.push(find());
		x = togo.front().first;
		y = togo.front().second;
		if (x == -1) break;
		visited[y][x] = true;
		bfs();
	}

	cout << ans;
}