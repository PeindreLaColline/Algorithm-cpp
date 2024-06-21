#include <iostream>
#include <vector>
using namespace std;

int n;
vector<pair<int, int>> taste;

int ans = 98765432;

void subs(int sour, int bitter, int ind, bool use) {
	if (ind == n) {
		if (use == false) return;
		if (ans > abs(bitter - sour)) ans = abs(bitter - sour);
		return;
	}
	subs(sour * taste[ind].first, bitter + taste[ind].second, ind + 1, true); //use
	subs(sour, bitter, ind + 1, use); //unuse
}

int main() {
	cin >> n;
	taste.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> taste[i].first >> taste[i].second; //sour bitter
	}

	subs(1, 0, 0, false);
	cout << ans;
}