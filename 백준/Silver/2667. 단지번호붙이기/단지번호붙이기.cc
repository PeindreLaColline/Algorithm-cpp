#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

int n;
vector<vector<int>> table;

int dir[4][4] = { {0, -1},{1, 0},{0, 1},{-1, 0} }; //x,y

vector<int> place;

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });

	int cx, cy;
	int nx, ny;
	int size = 1;
	table[y][x] = 0;

	while (q.size()) {
		cx = q.front().first;
		cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			nx = cx + dir[i][0];
			ny = cy + dir[i][1];
			
			if (nx >= n || ny >= n || nx < 0 || ny < 0) {
				continue;
			}
			if (table[ny][nx]==1) {
				table[ny][nx] = 0;
				size++;
				q.push({ nx, ny });
			}
			else {
				continue;
			}
		}
	}
	if (size) {
		place.push_back(size);
	}
}

int main() {
	cin >> n;
	
	vector<int> btmp(n);
	string s;
	for (int i = 0; i < n; i++) {
		table.push_back(btmp);
		cin >> s;
		for (int j = 0; j < n; j++) {
			table[i][j] = int(s[j]-'0');
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (table[i][j] == 1) {
				bfs(j, i);
			}
		}
	}

	sort(place.begin(), place.end());

	int i = 0;
	cout << place.size() << "\n";
	for (i; i < place.size()-1; i++) {
		cout << place[i] << "\n";
	}
	cout << place[i];
}