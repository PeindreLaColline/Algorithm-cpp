/*
14916 거스름돈
*/
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int ans = n / 5;
	n %= 5;
	if (n == 1 || n == 3) {
		if (ans < 1) ans = -1;
		else {
			ans--;
			n += 5;
			ans += n / 2;
		}
	}
	else if (n == 2 || n == 4) {
		ans += n / 2;
	}
	cout << ans;
}