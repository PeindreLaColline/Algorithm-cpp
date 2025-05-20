#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	priority_queue<int, vector<int>, less<int> > pq;
	int n;
	cin >> n;
	int buf;
	for (int i = 0; i < n; i++) {
		cin >> buf;
		if (buf == 0) {
			if (pq.empty()) {
				cout << 0 << "\n";
			}
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else {
			pq.push(buf);
		}
	}
}