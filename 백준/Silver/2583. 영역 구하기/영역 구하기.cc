#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<bool> btmp(102, false);
vector<vector<bool>> arr(102, btmp);
vector<vector<bool>> visited(102, btmp);

vector<pair<int, int>> dir(4);

int ans = 0;

void dfs(int y, int x) {
	if (visited[y][x] == true) return;
	if (arr[y][x] == true) return;

	visited[y][x] = true;
	ans++;

	for (int i = 0; i < 4; i++) {
		if (arr[y + dir[i].second][x + dir[i].first] == false) dfs(y + dir[i].second, x + dir[i].first);
	}
}

int main() {
	int m, n, k;
	cin >> m >> n >> k;

	//init
	dir[0] = { 1, 0 };
	dir[1] = { 0, 1 };
	dir[2] = { -1, 0 };
	dir[3] = { 0, -1 };

	for (int i = 0; i < n + 2; i++) {
		arr[0][i] = true;
		arr[m + 1][i] = true;
	}
	for (int i = 0; i < m + 2; i++) {
		arr[i][0] = true;
		arr[i][n + 1] = true;
	}

	int x1, y1, x2, y2;
	for (int t = 0; t < k; t++) {
		cin >> x1 >> y1 >> x2 >> y2;
		x1++; y1++; x2; y2;
		for (int i = x1; i <= x2; i++) {
			for (int j = y1; j <= y2; j++) {
				arr[j][i] = true;
			}
		}
	}

	vector<int> howbig;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == false) {
				if (visited[i][j] == false) {
					ans = 0;
					dfs(i, j);
					howbig.push_back(ans);
				}
			}
		}
	}

	sort(howbig.begin(), howbig.end());
	cout << howbig.size() << endl;
	for (int i = 0; i < howbig.size(); i++) {
		cout << howbig[i] << " ";
	}
}