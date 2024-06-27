#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<long long> road(n);
	vector<long long> oil(n);
	for (int i = 1; i < n; i++) {
		cin >> road[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> oil[i];
	}

	long long cheapest = oil[0], dis = 0;
	long long cost = oil[0] * road[0];

	for (int i = 0; i < n-1; i++) {
		dis += road[i+1];
		if (cheapest > oil[i + 1]) {
			cost += dis * cheapest;
			dis = 0;
			cheapest = oil[i + 1];
		}
	}
	cost += dis * cheapest;
	cout << cost;
}