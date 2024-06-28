#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> map;
bool done = false;

bool avail(int col, int row, int num) {
	//line check
	for (int i = 0; i < 9; i++) {
		if (map[row][i] == num) return false;
		if (map[i][col] == num) return false;
	}

	//square check
	int tcol = (col / 3) * 3;
	int trow = (row / 3) * 3;
	for (int i = tcol; i < tcol + 3; i++) {
		for (int j = trow; j < trow + 3; j++) {
			if (map[j][i] == num) return false;
		}
	}
	
	return true;
}

void sudoku(int col, int row) {
	if (done) return;

	//go to y+1, if it's the end of current x
	if (col == 9) {
		sudoku(0, row + 1);
		return;
	}

	//print sudoku if it's row 9, which means we reached to the end of y, the end of x
	if (row == 9) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << map[i][j] << " ";
			}
			cout << endl;
		}
		done = true;
		return;
	}

	//if it's 0, find available number, and put it in, and move to x+1
	if (map[row][col] == 0) {
		for (int i = 1; i <= 9; i++) {
			if (avail(col, row, i)) {
				map[row][col] = i;
				sudoku(col + 1, row);
			}
		}
		map[row][col] = 0;
		return;
	}

	sudoku(col + 1, row);
}

int main() {
	vector<int> itmp(9);
	for (int i = 0;i < 9; i++) {
		map.push_back(itmp);
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
		}
	}

	sudoku(0, 0);
}
