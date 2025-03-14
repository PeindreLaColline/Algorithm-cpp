#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;
int n;
int ans = 1;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second; //시작, 끝남
	}

	sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
		if (a.second != b.second) return a.second < b.second;
		else return a.first < b.first;
	});

	int cs = v[0].first;
	int ce = v[0].second;
	int s, e;
	for (int i = 1; i < n; i++) {
		s = v[i].first;
		e = v[i].second;
		if (s >= ce) {
			ans++;
			cs = s;
			ce = e;
		}
	}
	
	cout << ans;
}