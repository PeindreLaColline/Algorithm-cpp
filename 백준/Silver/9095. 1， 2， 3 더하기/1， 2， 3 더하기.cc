#include <iostream>
using namespace std;

int dp(int a) {
	if (a == 1) return 1;
	else if (a == 2) return 2;
	else if (a == 3) return 4;
	else {
		return dp(a - 1) + dp(a - 2) + dp(a - 3);
	}
}

int main() {
	int T;
	cin >> T;

	int n;
	for (int test_case = 0; test_case < T; test_case++) {
		//init
		cin >> n;

		cout << dp(n) << endl;
	}
}