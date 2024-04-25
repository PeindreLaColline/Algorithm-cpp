#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int n, m;
vector<vector<int>> map;
vector<vector<int>> fuel;
vector<vector<bool>> visited;
int bx, by;
int tx, ty;

int dx[] = { 1, 1, 1, 0, -1, -1, -1, 0 };
int dy[] = { 1, 0, -1, 1, 1, 0, -1, -1 };

void bfs() {
	queue<pair<int, int>> q;
	int cx, cy;
	int nx, ny;

	q.push({ bx, by });
	fuel[by][bx] = 0;

	while (q.size()) {
		cx = q.front().first;
		cy = q.front().second;
		q.pop();

		if (visited[cy][cx] == true) continue;
		visited[cy][cx] = true;

		for (int i = 0; i < 8; i++) {
			nx = cx + dx[i];
			ny = cy + dy[i];
			if (nx <= 0 || ny <= 0 || nx > m || ny > n) continue;
			if (map[ny][nx] == -1) continue;
			if (i <= 2) {
				if (fuel[ny][nx] > fuel[cy][cx]) {
					visited[ny][nx] = false;
					fuel[ny][nx] = fuel[cy][cx];

					if (map[ny][nx] == 2) break;
					q.push({ nx, ny });
				}
			}
			else{
				if (fuel[ny][nx] > fuel[cy][cx] + 1) {
					visited[ny][nx] = false;
					if (map[ny][nx] == 2) {
						fuel[ny][nx] = fuel[cy][cx] + 1;
						//q.push({ nx, ny });
						break;
					}
					else if (map[ny][nx] != 2) {
						fuel[ny][nx] = fuel[cy][cx] + 1;
						q.push({ nx, ny });
					}
				}
			}
		}
	}
}

int main() {
	cin >> n >> m;

	vector<int> mtmp(m+1);
	vector<int> ftmp(m+1, 98765432);
	vector<bool> btmp(m + 1, false);
	map.push_back(mtmp);
	fuel.push_back(ftmp);
	visited.push_back(btmp);
	string s;
	for (int i = 1; i <= n; i++) {
		map.push_back(mtmp);
		fuel.push_back(ftmp);
		visited.push_back(btmp);
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == '.') map[i][j+1] = 1; //바다
			else if (s[j] == '#') map[i][j+1] = -1; //암초
			else if (s[j] == 'K') { //배
				map[i][j+1] = 1;
				bx = j+1;
				by = i;
			}
			else if (s[j] == '*') { //보물
				map[i][j+1] = 2;
				tx = j+1;
				ty = i;
			}
		}
	}
	bfs();
	if (fuel[ty][tx] == 98765432) cout << -1;
	else cout << fuel[ty][tx];
}