#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<bool> visited;
vector<int> line;

void all_print() {
	for (int i = 0; i < m; i++) {
		cout << line[i] << " ";
	}
	cout << "\n";
}

void combi(int cnt) {
	if (cnt == m) {
		all_print();
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (visited[i] == true) continue;
		visited[i] = true;
		line[cnt] = i;
		combi(cnt + 1);
		visited[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	visited.resize(n + 1, false);
	line.resize(m);

	combi(0);
}