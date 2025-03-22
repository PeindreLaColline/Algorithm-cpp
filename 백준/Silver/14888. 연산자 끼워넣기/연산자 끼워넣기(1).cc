#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> num;

vector<int> op(4);
vector<int> op_ord;
vector<bool> visited;

vector<bool> pl;
vector<bool> mi;
vector<bool> mu;
vector<bool> di;

int maxi = -1987654321;
int mini = 1987654321;

int get_result() {
	int tmp = num[0];
	for (int i = 0; i < n - 1; i++) {
		if (op_ord[i] == 0) {
			tmp += num[i + 1];
		}
		else if (op_ord[i] == 1) {
			tmp -= num[i + 1];
		}
		else if (op_ord[i] == 2) {
			tmp *= num[i + 1];
		}
		else if (op_ord[i] == 3) {
			tmp /= num[i + 1];
		}
	}
	return tmp;
}

void dfs(int cnt) {
	if (cnt == n - 1) {
		int tmp = get_result();
		if (tmp > maxi) maxi = tmp;
		if (tmp < mini) mini = tmp;
		return;
	}

	if (op[0]) {
		for (int i = 0; i < n - 1; i++) {
			if (visited[i]) continue;
			if (pl[i]) continue;

			visited[i] = true;
			pl[i] = true;
			op[0]--;

			op_ord[i] = 0;
			dfs(cnt + 1);

			op[0]++;
			visited[i] = false;
			pl[i] = false;
		}
	}
	else if (op[1]) {
		for (int i = 0; i < n - 1; i++) {
			if (visited[i]) continue;
			if (mi[i]) continue;

			visited[i] = true;
			mi[i] = true;
			op[1]--;

			op_ord[i] = 1;
			dfs(cnt + 1);

			op[1]++;
			visited[i] = false;
			mi[i] = false;
		}
	}
	else if (op[2]) {
		for (int i = 0; i < n - 1; i++) {
			if (visited[i]) continue;
			if (mu[i]) continue;

			visited[i] = true;
			mu[i] = true;
			op[2]--;

			op_ord[i] = 2;
			dfs(cnt + 1);

			op[2]++;
			visited[i] = false;
			mu[i] = false;
		}
	}
	else if (op[3]) {
		for (int i = 0; i < n - 1; i++) {
			if (visited[i]) continue;
			if (di[i]) continue;

			visited[i] = true;
			di[i] = true;
			op[3]--;

			op_ord[i] = 3;
			dfs(cnt + 1);

			op[3]++;
			visited[i] = false;
			di[i] = false;
		}
	}
}

int main() {
	cin >> n;

	num.resize(n);
	op_ord.resize(n - 1);
	visited.resize(n - 1, false);

	pl.resize(n - 1, false);
	mi.resize(n - 1, false);
	mu.resize(n - 1, false);
	di.resize(n - 1, false);

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}

	dfs(0);
	cout << maxi << endl;
	cout << mini;
}
