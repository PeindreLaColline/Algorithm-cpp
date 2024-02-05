#include <iostream>
#include <stack>
using namespace std;

int main() {
	int K;
	cin >> K;

	stack<int> number;
	int tmp;
	for (int i = 0; i < K; i++) {
		cin >> tmp;
		if (tmp == 0) {
			number.pop();
		}
		else {
			number.push(tmp);
		}
	}

	int ans = 0;
	while (true) {
		if (number.empty() == true) {
			break;
		}
		else {
			ans += number.top();
			number.pop();
		}
	}

	cout << ans;
}
