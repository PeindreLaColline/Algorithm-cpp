#include <iostream>
#include <vector>
using namespace std;

vector<int> itmp(52, 0);
vector<vector<int>> arr(52, itmp);

vector<bool> btmp(52, false);
vector<vector<bool>> visited(52, btmp);

int m, n, k;

vector<pair<int, int>> dir(4);

void dfs(int x, int y) {
	if (visited[y][x] == true) return;
	if (arr[y][x] == 2) return;

	visited[y][x] = true;

	for (int i = 0; i < 4; i++) {
		if (arr[y + dir[i].second][x + dir[i].first] == 1) dfs(x + dir[i].first, y + dir[i].second);
	}
}

int main() {
	int T;
	cin >> T;
	
	dir[0] = { 1, 0 };
	dir[1] = { 0, 1 };
	dir[2] = { -1, 0 };
	dir[3] = { 0, -1 };

	int x, y;
	for (int test_case = 0; test_case < T; test_case++) {
		cin >> m >> n >> k;
		
		//init
		for (int i = 0; i <= n; i++) {
			arr[i] = itmp;
			visited[i] = btmp;
		}

		for (int i = 0; i < m+2; i++) {
			arr[0][i] = 2;
			arr[n + 1][i] = 2;
		}

		for (int i = 0; i < n+2; i++) {
			arr[i][0] = 2;
			arr[i][m + 1] = 2;
		}

		//input
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			arr[y+1][x+1] = 1;
		}

		//dfs
		int block = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (arr[i][j] == 1) {
					if (visited[i][j] == false) {
						dfs(j, i);
						block++;
					}
				}
			}
		}

		cout << block << endl;
	}
}