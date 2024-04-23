#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a;
vector<int> b;

void compare() {
	
}

void a_bigger() {
	
}

void b_bigger() {

}

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

		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i] > b[j]) ans++;
				else break;
			}
		}
		cout << ans << endl;
	}
}