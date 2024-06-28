#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> avail;
int ans = 0;

bool check_avail(int row) {
	for (int i = 0; i < row; i++) {
		if (avail[row] == avail[i]) return false;
		if (abs(avail[row] - avail[i]) == row - i) return false;
	}
	return true;
}

void nqueen(int row) {
	if (!check_avail(row - 1)) return;
	if (row == n) {
		ans++;
		return;
	}
	for (int i = 0; i < n; i++) {
		avail[row] = i;
		nqueen(row + 1);
	}
}

int main() {
	cin >> n;
	avail.resize(n);
	nqueen(0);
	cout << ans;
}