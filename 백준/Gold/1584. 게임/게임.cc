#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> itmp(501, 0); //안전
vector<vector<int>> map(501, itmp);
vector<int> tmp(501, 98765432);
vector<vector<int>> arr(501, tmp);

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

void bfs() {
	queue<pair<int, int>> q;
	int cx, cy;
	int nx, ny;
	q.push({ 0,0 });
	arr[0][0] = 0;

	while (q.size()) {
		cx = q.front().first;
		cy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			nx = cx + dx[i];
			ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx > 500 || ny>500) continue;
			if (map[ny][nx] == -1) continue;
			if (arr[ny][nx] > arr[cy][cx] + map[ny][nx]) {
				arr[ny][nx] = arr[cy][cx] + map[ny][nx];
				q.push({ nx, ny });
			}
		}
	}
}

int main() {
	int n, m;
	int x1, y1, x2, y2;

	cin >> n;
	while (n) {
		n--;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 > x2)swap(x1, x2);
		if (y1 > y2) swap(y1, y2);
		for (int i = y1; i <= y2; i++) {
			for (int j = x1; j <= x2; j++) {
				map[i][j] = 1; //위험
			}
		}
	}

	cin >> m;
	while (m) {
		m--;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 > x2)swap(x1, x2);
		if (y1 > y2) swap(y1, y2);
		for (int i = y1; i <= y2; i++) {
			for (int j = x1; j <= x2; j++) {
				map[i][j] = -1; //죽음
			}
		}
	}

	bfs();
	int ans = arr[500][500];
	if (ans == 98765432) cout << -1;
	else cout << ans;
}