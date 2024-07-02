#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> p;
int ans = 0;

void make() {
	p.resize(n + 1);
	for (int i = 0; i < n + 1; i++) {
		p[i] = i;
	}
}

int find(int a) {
	if (p[a] == a) return a;
	return p[a] = find(p[a]);
}

void unite(int a, int b) {
	int ar = find(a);
	int br = find(b);
	if (ar == br) return;
	p[br] = ar;
	return;
}

int main() {
	cin >> n >> m;

	make();

	int t1, t2;
	for (int i = 0; i < m; i++) {
		cin >> t1 >> t2;
		unite(t1, t2);
	}

	for (int i = 1; i <= n; i++) {
		find(i);
	}

	int from, to;
	cin >> from;
	for (int i = 0; i < n - 1; i++) {
		cin >> to;
		if (p[from] != p[to]) ans++;
		from = to;
	}

	cout << ans;
}