#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	n = 1000 - n;

	int coin[] = { 500, 100, 50, 10, 5, 1 };
	
	int ans = 0;
	for (int i = 0; i < 6; i++) {
		while (true) {
			if (n - coin[i] >= 0) {
				n = n - coin[i];
				ans++;
			}
			else break;
		}
	}
	cout << ans;
}