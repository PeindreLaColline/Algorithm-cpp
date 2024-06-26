#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	vector<int> ans;

	string T, P;
	getline(cin, T);
	getline(cin, P);

	vector<int> F(P.size());

	for (int t = 1, p = 0; t < P.size(); t++) {
		while (p > 0 && P[t] != P[p]) p = F[p - 1];
		if (P[t] == P[p]) F[t] = ++p;
	}

	for (int t = 0, p = 0; t < T.size(); t++) {
		while (p > 0 && T[t] != P[p]) p = F[p - 1];
		if (T[t] == P[p]) {
			if (p == P.size() - 1) {
				ans.push_back(t - p);
				p = F[p];
			}
			else {
				p++;
			}
		}
	}

	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i]+1 << " ";
	}
}