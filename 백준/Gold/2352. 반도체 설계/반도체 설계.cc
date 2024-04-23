#include <iostream>
#include <vector>
using namespace std;

int target;
vector<int> arr;

void binary(int s, int e) {
	int mid, f, b;
	int size = e;
	while (s <= e) {
		mid = (s + e) / 2;
		f = mid - 1;
		b = mid + 1;
		if (f >= 0) {
			if (arr[f] < target && arr[mid] > target) {
				arr[mid] = target;
				return;
			}
		}
		if (b <= size) {
			if (arr[mid] < target && target < arr[b]) {
				arr[b] = target;
				return;
			}
		}
		if (arr[mid] > target) e = mid - 1;
		else if (arr[mid] < target) s = mid + 1;
	}
	arr[0] = target;
}

int main() {
	int n;
	cin >> n;
	
	cin >> target;
	arr.push_back(target);
	for (int i = 0; i < n - 1; i++) {
		cin >> target;
		if (target > arr[arr.size() - 1]) {
			arr.push_back(target);
			continue;
		}
		binary(0, arr.size());
	}
	cout << arr.size();
}