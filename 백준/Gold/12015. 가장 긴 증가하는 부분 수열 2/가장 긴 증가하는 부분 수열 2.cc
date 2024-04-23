#include <iostream>
#include <vector>
using namespace std;

int tmp;
vector<int> v;

void binary(int s, int e) {
	int mid, f, b;
	while (s <= e) {
		mid = (s + e) / 2;
		f = mid - 1;
		b = mid + 1;
		if (v[mid] == tmp) return;
		if (v[f] < tmp && tmp < v[mid]) {
			v[mid] = tmp;
			return;
		}
		if (v[mid] < tmp && tmp < v[b]) {
			v[b] = tmp;
			return;
		}
		if (v[mid] > tmp) e = mid - 1;
		else if (v[mid] < tmp) s = mid + 1;
	}
	v[0] = tmp;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	cin >> tmp;
	v.push_back(tmp);

	for (int i = 0; i < n-1; i++) {
		cin >> tmp;
		if (v[v.size() - 1] < tmp) {
			v.push_back(tmp);
			continue;
		}
		else {
			binary(0, v.size() - 1);
		}
	}
	cout << v.size();
}