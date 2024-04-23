#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int input;

void binary(int s, int e) {
	int mid;
	int f;
	int b;
	while (s <= e) {
		mid = (s + e) / 2;
		f = mid - 1;
		b = mid + 1;
		if (v[mid] == input) return;
		else {
			if (v[f]<input && v[mid] > input) {
				v[mid] = input;
				return;
			}
			else if (v[mid] < input && v[b] > input) {
				v[b] = input;
				return;
			}
			if (v[mid] > input) e = mid - 1;
			else if (v[mid] < input) s = mid + 1;
		}
	}
	v[0] = input;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	cin >> input;
	v.push_back(input);

	for (int i = 0; i < n - 1; i++) {
		cin >> input;
		if (v[v.size() - 1] < input) {
			v.push_back(input);
			continue;
		}
		else {
			binary(0, v.size() - 1);
		}
	}
	cout << v.size();
}