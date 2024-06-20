#include <iostream>
#include <vector>
using namespace std;

int n;
vector<bool> visited;
vector<int> line;

void all_print() {
	for (int i = 0; i < n; i++) {
		cout << line[i] << " ";
	}
	cout << "\n";
}

void combi(int cnt) {
	if (cnt == n) {
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

	cin >> n;
	visited.resize(n + 1, false);
	line.resize(n);

	combi(0);
}