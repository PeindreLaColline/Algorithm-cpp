#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a;
vector<int> b;

int main() {
	int n, m;
	int test;
	cin >> test;
	for (int t = 0; t < test; t++) {
		cin >> n >> m;

		a.resize(n);
		b.resize(m);

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> b[i];
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		int j = 0;
		int ans = 0;
		int pa = 0;
		int pre = 0;
		for (int i = 0; i < n; i++) {
			if (pa == a[i]) {
				ans += pre;
				continue;
			}
			while (true) {
				if (j >= m) {
					ans += pre;
					break;
				}
				if (a[i] > b[j]) {
					pre++;
					j++;
				}
				else if (a[i] <= b[j]) {
					ans += pre;
					pa = a[i];
					break;
				}
			}
		}
		cout << ans<<endl;
	}

}