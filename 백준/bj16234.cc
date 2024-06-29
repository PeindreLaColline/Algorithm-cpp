#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, l, r;
vector<vector<int>> map;
vector<vector<bool>> visited;
vector<vector<bool>> init;

queue<pair<int, int>> togo;
queue<pair<int, int>> ntogo;
queue<pair<int, int>> vide;
int day = 0;

int dir[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };

bool wasin = false;

int fi, fj;
pair<int, int> find_place() {
	for (fi; fi < n; fi++) {
		for (fj; fj < n; fj++) {
			if (!visited[fi][fj]) return { fj, fi };
		}
	}
	return { -1, -1 };
}

void bfs() {
	int cx, cy, nx, ny;
	int cpop;
	int dif;
	vector<pair<int, int>> hist;
	int sum = 0;

	//ntogo 없이 그냥 togo만 해도 될 것 같음
	while (!ntogo.empty()) {
		togo = ntogo;
		ntogo = vide;

		visited = init;
		while (!togo.empty()) {
			cx = togo.front().first;
			cy = togo.front().second;
			togo.pop();

			hist.push_back({ cx, cy });
			sum += map[cy][cx];
			cpop = map[cy][cx];

			for (int i = 0; i < 4; i++) {
				nx = cx + dir[i][0];
				ny = cy + dir[i][1];
				
				if ( 0 <= nx && nx > n && 0 <= ny && ny > n) {
					if (!visited[ny][nx]) {
						dif = map[ny][nx] - cpop;
						if (l <= dif && dif <= r) {
							ntogo.push({ nx, ny });
							visited[ny][nx] = true;
						}
					}
				}
			}
		}
	}

	if (!hist.empty()) wasin = true;
	sum /= hist.size();
	for (int i = 0; i < hist.size(); i++) {
		map[hist[i].second][hist[i].first] = sum;
	}
}

int main() {
	cin >> n >> l >> r;
	vector<int> itmp(n);
	vector<bool> btmp(n, false);
	for (int i = 0; i < n; i++) {
		map.push_back(itmp);
		visited.push_back(btmp);
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	init = visited;

	while (true) { //day
		day++;
		visited = init;
		fi = 0; fj = 0;
		ntogo = vide;
		wasin = false;

		while (true) { //union
			ntogo.push(find_place());
			if (ntogo.front().first == -1) break;
			bfs();
		}
		
		if (!wasin) break;
	}

	cout << day;
}
