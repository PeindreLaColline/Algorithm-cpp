#include <iostream>
#include <vector>
using namespace std;

int n, m, r;
int quest;
vector<vector<int>> map(100);
vector<vector<int>> tmp(100);

void all_print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

void right(int gs, int ge, int ss, int se) {
	for (int i = ss; i <= se; i++) {
		for (int j = gs; j <= ge; j++) {
			map[i][j + m/2] = tmp[i][j];
		}
	}
}

void left(int gs, int ge, int ss, int se) {
	for (int i = ss; i <= se; i++) {
		for (int j = gs; j <= ge; j++) {
			map[i][j -m/2] = tmp[i][j];
		}
	}
}

void down(int gs, int ge, int ss, int se) {
	for (int i = ss; i <= se; i++) {
		for (int j = gs; j <= ge; j++) {
			map[i + n/2][j] = tmp[i][j];
		}
	}
}

void up(int gs, int ge, int ss, int se) {
	for (int i = ss; i <= se; i++) {
		for (int j = gs; j <= ge; j++) {
			map[i - n/2][j] = tmp[i][j];
		}
	}
}

void one() {
	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < m;j++) {
			swap(map[i][j], map[n - i -1 ][j]);
		}
	}
}

void two() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m / 2; j++) {
			swap(map[i][j], map[i][m-j - 1]);
		}
	}
}

void three() {
	tmp = map;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			map[j][n -1 - i] = tmp[i][j];
		}
	}
	swap(n, m);
}

void four() {
	tmp = map;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			map[m-1-j][i] = tmp[i][j];
		}
	}
	swap(n, m);
}

void five() {
	tmp = map;
	right(0, m / 2 -1, 0, n / 2 - 1);
	down(m / 2 - 1, m - 1, 0, n / 2 - 1);
	left(m / 2, m - 1, n / 2 - 1, n - 1);
	up(0, m / 2 - 1, n / 2, n - 1);
}

void six() {
	tmp = map;
	down(0, m / 2 - 1, 0, n / 2 - 1);
	right(0, m / 2 - 1, n / 2, n - 1);
	up(m / 2, m - 1, n / 2, n - 1);
	left(m / 2, m - 1, 0, n / 2 - 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> r; //n세로 m가로
	
	vector<int> vtmp(100, 0);
	for (int i = 0; i < 100; i++) {
		map[i] = vtmp;
		tmp[i] = vtmp;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	

	for (int i = 0; i < r; i++) {
		cin >> quest;
		if (quest == 1) one();
		else if (quest == 2) two();
		else if (quest == 3) three();
		else if (quest == 4) four();
		else if (quest == 5) five();
		else if (quest == 6) six();
	}

	all_print();
}