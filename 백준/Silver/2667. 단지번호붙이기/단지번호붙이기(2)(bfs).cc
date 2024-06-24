#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int dir[4][2] = { {0,-1},{1,0},{0,1},{-1, 0 } };

int n;
vector<vector<int>> map;
vector<vector<bool>> visited;
queue<pair<int, int>> togo;

vector<int> ans;

int num;

void bfs(){
	int cx = togo.front().first;
	int cy = togo.front().second;
	togo.pop();
	visited[cy][cx] = true;
	num++;
	for (int i = 0; i < 4; i++) {
		int nx = cx + dir[i][0];
		int ny = cy + dir[i][1];
		if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[ny][nx] && map[ny][nx]) {
			togo.push({ nx, ny });
			visited[ny][nx] = true;
			bfs();
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	vector<int> vtmp(n);
	vector<bool> btmp(n, false);
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		map.push_back(vtmp);
		visited.push_back(btmp);
		for (int j = 0; j < n; j++) {
			map[i][j] = int(s[j]-'0');
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && map[i][j]) {
				num = 0;
				togo.push({ j, i });
				visited[i][j] = true;
				bfs();
				ans.push_back(num);
			}
		}
	}

	sort(ans.begin(), ans.end());

	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}
	
}
