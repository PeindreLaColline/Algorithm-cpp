#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int tmp;

void binary(int s, int e) {
	int mid, f, b;
	int size = v.size();
	while (s <= e) {
		mid = (s + e) / 2;
		f = mid - 1;
		b = mid + 1;
		if (f >= 0) {
			if (v[f] < tmp && tmp < v[mid]) {
				v[mid] = tmp;
				return;
			}
		}
		if (b <= size - 1) {
			if (v[mid] < tmp && tmp < v[b]) {
				v[b] = tmp;
				return;
			}
		}
		if (v[mid] < tmp) s = mid + 1;
		else if (v[mid] > tmp) e = mid - 1;
	}
	v[0] = tmp;
}

int main() {
	int n;
	cin >> n;

	cin >> tmp;
	v.push_back(tmp);
	for (int i = 0; i < n-1; i++) {
		cin >> tmp;
		if (tmp > v[v.size() - 1]) {
			v.push_back(tmp);
			continue;
		}
		binary(0, v.size() - 1);
	}

	cout << n - v.size();
}