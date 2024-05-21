#include <iostream>
#include <vector>
using namespace std;

#define WHITE 1
#define BLACK 0

vector<vector<bool>> table;
vector<vector<bool>> white;
int col, row;
int ans = 98765432;

int get_sum(int a, int b) {
	int num = 0;
	for (int i = a; i < a + 8; i++) {
		for (int j = b; j < b + 8; j++) {
			num += white[i][j];
		}
	}
	return num;
}

void brute(int i) {
	if (i + 8 > col) return;
	int sum;
	for (int j = 0; j <= row - 8; j++) {
		sum = get_sum(i, j);
		ans = min(ans, min(sum, 64 - sum));
	}
	brute(i + 1);
}

int main() {
	cin >> col >> row;
	vector<bool> btmp(row, false);
	char c;
	int num;
	for (int i = 0; i < col; i++) {
		table.push_back(btmp);
		white.push_back(btmp);
		for (int j = 0; j < row; j++) {
			if (i % 2 == j % 2) {
				table[i][j] = WHITE;
			}
			cin >> c;
			if (c == 'W') num = WHITE;
			else num = BLACK;
			if (table[i][j] == num) continue;
			else white[i][j] = 1;
		}
	}
	brute(0);
	cout << ans;
}