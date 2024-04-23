#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;

long long target = 0;
bool ex = false;

void binary(int s, int e) {
	long long mid = (s + e) / 2;
	if (arr[mid] == target) {
		ex = true;
		return;
	}
	if (s <= e) {
		ex = false;
		return;
	}
	if (arr[mid] < target) {
		binary(mid + 1, e);
	}
	else if (arr[mid] > target) {
		binary(s, mid - 1);
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n;

	arr.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> target;
		ex = false;
		if (target > arr[n - 1] || arr[0] > target) {
			cout << 0 << '\n';
			continue;
		}
		else if (target == arr[0] || target == arr[n - 1]) {
			cout << 1 << '\n';
			continue;
		}
		binary(0, n - 1);
		if (ex == true) cout << 1 << '\n';
		else if (ex == false) cout << 0 << '\n';
	}
}
