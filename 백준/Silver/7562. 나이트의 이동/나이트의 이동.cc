#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int col, row;
int sx, sy;
int dx, dy;
vector<vector<bool>> map;
vector<pair<int, int>> dir(8); //x, y

int times; //num of repeat

void bfs() {
	int cx, cy;
	int nx, ny;
	queue<pair<int, int>> q;
	queue<pair<int, int>> pre_q;

	pre_q.push({ sx,sy });
	map[sy][sx] = true;

	if (dy == sy && dx == sx) return;
	while (!pre_q.empty()) {
		q = pre_q;
		while (!pre_q.empty()) pre_q.pop();

		while (!q.empty()) {
			cx = q.front().first;
			cy = q.front().second;
			q.pop();

			for (int i = 0; i < 8; i++) {
				nx = cx + dir[i].first;
				ny = cy + dir[i].second;

				if (nx < 0 || ny < 0 || nx >= row || ny >= col || map[ny][nx]) continue;
				map[ny][nx] = true;
				if (ny == dy && nx == dx) {
					times++; 
					return;
				}
				pre_q.push({ nx, ny });
			}
		}
		if (!pre_q.empty()) times++;
	}
}

int main() {
	//init
	dir[0] = { 1, -2 }; dir[1] = { 2, -1 }; dir[2] = { 2, 1 }; dir[3] = { 1, 2 };
	dir[4] = { -1, 2 }; dir[5] = { -2, 1 }; dir[6] = { -2, -1 }; dir[7] = { -1, -2 };

	int T;
	cin >> T;
	for (int test_case = 0; test_case < T; test_case++) {	
		//init
		times = 0;

		//input
		cin >> col;
		row = col;
		cin >> sx >> sy;
		cin >> dx >> dy;
		
		map.clear();
		vector<bool> btmp(row, false);
		for (int i = 0; i < col; i++) {
			map.push_back(btmp);
		}

		bfs();
		cout << times << endl;
	}
}