#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<char> ctmp(102, 'X');
vector<vector<char>> arr(102, ctmp);

vector<bool> btmp(102, false);
vector<vector<bool>> visited(102, btmp);

vector<pair<int, int>> dir(4);

void non_blind(int col, int row) {
	if (visited[col][row] == true) return;
	if (arr[col][row] == 'X') return;

	visited[col][row] = true;
	char color = arr[col][row];

	for (int i = 0; i < 4; i++) {
		if (visited[col + dir[i].second][row + dir[i].first] == false) {
			if (arr[col + dir[i].second][row + dir[i].first] == color) {
				non_blind(col + dir[i].second, row + dir[i].first);
			}
		}
	}
}

void blind(int col, int row) {
	if (visited[col][row] == true) return;
	if (arr[col][row] == 'X') return;

	visited[col][row] = true;
	char color = arr[col][row];

	for (int i = 0; i < 4; i++) {
		char ccolor = arr[col + dir[i].second][row + dir[i].first];
		if (visited[col + dir[i].second][row + dir[i].first] == false) {
			if (color == 'R' || color == 'G') {
				if (ccolor == 'R' || ccolor == 'G') {
					blind(col + dir[i].second, row + dir[i].first);
				}
			}
			else if (color == 'B') {
				if (ccolor == 'B') {
					blind(col + dir[i].second, row + dir[i].first);
				}
			}
		}
	}
}

int main() {
	int n;
	cin >> n;

	string s;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		for (int j = 1; j <= n; j++) {
			arr[i][j]= s[j - 1];
		}
	}

	dir[0] = { 1, 0 };
	dir[1] = { 0, 1 };
	dir[2] = { -1, 0 };
	dir[3] = { 0, -1 };

	int nonblind_block = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (visited[i][j] == false) {
				non_blind(i, j);
				nonblind_block++;
			}
		}
	}

	for (int i = 0; i <= n; i++) {
		visited[i] = btmp;
	}

	int blind_block = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (visited[i][j] == false) {
				blind(i, j);
				blind_block++;
			}
		}
	}

	cout << nonblind_block << " " << blind_block;
}