#include <iostream>
#include<vector>
#include <string>
#include <queue>
using namespace std;

int n, m;
int jx, jy;
int bx, by;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

vector<vector<bool>> map;
vector<vector<bool>> inlist;
int cnt = 0;

void bfs() {
	queue<pair<int, int>> q;
	queue<pair<int, int>> nq;
	queue<pair<int, int>> emp;

	int cx, cy;
	int nx, ny;

	inlist[jy][jx] = true;
	nq.push({ jx, jy });

	while (nq.size()) {
		q = nq;
		nq = emp;
		cnt++;
		while (q.size()) {
			cx = q.front().first;
			cy = q.front().second;
			q.pop();
			
			if (cx == bx && cy == by) return;

			for (int i = 0; i < 4; i++) {
				nx = cx + dx[i];
				ny = cy + dy[i];
				if (ny<0 || nx<0 || nx>m - 1 || ny>n - 1 || inlist[ny][nx]) continue;

				if (map[ny][nx] == 0) {
					inlist[ny][nx] = true;
					q.push({ nx, ny });
				}
				else if (map[ny][nx] == 1) {
					inlist[ny][nx] = true;
					nq.push({ nx, ny });
				}
			}
		}
	}
	
}

int main() {
	cin >> n >> m;
	cin >> jy >> jx >> by >> bx;
	jy--; jx--;
	by--; bx--;

	vector<bool> btmp(m, false);
	string s;
	for (int i = 0; i < n; i++) {
		map.push_back(btmp);
		inlist.push_back(btmp);
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == '0') map[i][j] = 0;
			else map[i][j] = 1;
		}
	}
	
	bfs();
	cout << --cnt;
}