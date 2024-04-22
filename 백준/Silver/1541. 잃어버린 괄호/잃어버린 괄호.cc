#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;

	vector<int> v;

	int num = 0;
	
	v.push_back(0);

	for (char ch : s) {
		if (isdigit(ch)) {
			num *= 10;
			num += (int(ch - '0'));
		}
		else {
			v[v.size() - 1] += num;
			num = 0;
			if (ch == '-') {
				v.push_back(0);
			}
		}
	}

	int ans = 0;
	if (v.size() == 1) {
		ans = v[0] + num;
	}
	else {
		ans += v[0];
		for (int i = 1; i < v.size(); i++) {
			ans -= v[i];
		}
		ans -= num;
	}

	cout << ans;
}