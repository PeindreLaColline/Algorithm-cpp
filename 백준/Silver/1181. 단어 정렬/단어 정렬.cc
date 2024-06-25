#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;
vector<string> v;

bool compare(string a, string b) {
	if (a.size() != b.size()) {
		return a.size() < b.size();
	}
	else {
		return a < b;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	v.resize(n);
	string s;
	for (int i = 0;i < n; i++) {
		cin >> s;
		v[i] = s;
	}
	sort(v.begin(), v.end(), compare);

	cout << v[0] << endl;
	for (int i = 1; i < n; i++) {
		if (v[i] == v[i - 1]) continue;
		cout << v[i] << endl;
	}
}