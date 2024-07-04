#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int l, c;
vector<char> alpha;
vector<char> code;

void back(int vow, int con, int start, int cur) {
	if (cur == l) {
		if (vow >= 1 && con >= 2) {
			for (int i = 0; i < l; i++) {
				cout << code[i];
			}
			cout << endl;
		}
		return;
	}
	if (start == c) return;

	for (int i = start + 1; i < c; i++) {
		char tmp = alpha[i];
		code[cur] = tmp;
		if (tmp == 'a' || tmp == 'e' || tmp == 'i' || tmp == 'o' || tmp == 'u') {
			back(vow + 1, con, i, cur + 1);
		}
		else {
			back(vow, con + 1, i, cur + 1);
		}
	}
}

int main() {
	cin >> l >> c;
	alpha.resize(c);
	code.resize(l);
	for (int i = 0; i < c; i++) {
		cin >> alpha[i];
	}
	sort(alpha.begin(), alpha.end());

	back(0, 0, -1, 0);
}