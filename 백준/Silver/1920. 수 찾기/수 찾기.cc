#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;
long long target = 0;

int binary(int s, int e) {
	long long mid;
	while (s <= e) {
		mid = (s + e) / 2;
		if (arr[mid] == target) return 1;
		else if (arr[mid] > target) e = mid - 1;
		else s = mid + 1;
	}	
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n;

	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		arr.push_back(tmp);
	}
	sort(arr.begin(), arr.end());

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> target;
		if (target > arr[n - 1] || arr[0] > target) {
			cout << 0 << '\n';
			continue;
		}
		else if (target == arr[n - 1] || arr[0] == target) {
			cout << 1 << "\n";
			continue;
		}
		cout << binary(0, n - 1) << '\n';
	}
}