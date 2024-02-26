#include <iostream>
using namespace std;

int board[1025][1025];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//init
	int n, m;
	cin >> n >> m;

	//input
	int tmp;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> tmp;
			board[i][j] = board[i][j - 1] + board[i - 1][j] + tmp - board[i - 1][j - 1];
		}
	}

	//get answer
	int x1, y1, x2, y2;
	for (int i = 0; i < m; i++) {
		cin >> y1 >> x1 >> y2 >> x2;
		cout << board[y2][x2] - board[y2][x1 - 1] - board[y1 - 1][x2] + board[y1 - 1][x1 - 1] << '\n';
	}

	return 0;
}