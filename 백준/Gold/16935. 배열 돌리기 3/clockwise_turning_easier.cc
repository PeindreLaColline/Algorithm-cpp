#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<vector<int>> a;
	int n, m, tmp;

	//clockwise
	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < m / 2; j++) {
			tmp = a[i][j];
			a[n / 2 + i][j] = a[n / 2 + i][m / 2 + j];
			a[n / 2 + i][m / 2 + j] = a[i][m / 2 + j];
			a[i][m / 2 + j] = tmp;
		}
	}

	//counterclockwise
	//...
}
