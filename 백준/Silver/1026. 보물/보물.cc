#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), compare);

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += a[i] * b[i];
	}

	cout << ans;

}