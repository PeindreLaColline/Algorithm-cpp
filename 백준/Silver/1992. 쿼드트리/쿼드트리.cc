#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
vector<vector<int>> map;
vector<char> ans;

int color;

bool check_done(int x, int y, int size) {
	int tmp = map[y][x];
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (tmp != map[i][j]) return false;
		}
	}
	color = map[y][x];
	return true;
}

void divide(int x, int y, int size) {
	
	if (check_done(x, y, size)) {
		ans.push_back(color);
		return;
	}
	ans.push_back('(');
	size /= 2;
	divide(x, y, size);
	divide(x +size, y, size);
	divide(x, y + size, size);
	divide(x + size, y + size, size);
	ans.push_back(')');
}

int main() {
	cin >> n;
	vector<int> itmp(n);

	string s;
	for (int i = 0; i < n; i++) {
		map.push_back(itmp);
		cin >> s;
		for (int j = 0; j < n; j++) {
			map[i][j] = s[j];
		}
	}
	divide(0, 0, n);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
	}
}