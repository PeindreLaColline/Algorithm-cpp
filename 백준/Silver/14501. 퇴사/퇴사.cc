#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 15

int N;
int ans = 0;
vector<pair<int, int>> plan(MAX);
vector<bool> noneed(MAX, false);

void outcome(int start, int cur_ans) {
	if (ans < cur_ans) ans = cur_ans;

	queue<int> togo;
	for (int i = start + plan[start].first; i < N; i++) {
		if (noneed[i] == true) continue;
		else togo.push(i);
	}

	int tmp;
	while (!togo.empty()) {
		tmp = togo.front();
		togo.pop();
		outcome(tmp, cur_ans + plan[tmp].second);
	}
}

int main() {
	cin >> N;
	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		if ((a + i) > N) {
			plan[i] = { a, 0 };
			noneed[i] = true;
		}
		else plan[i] = { a, b };
	}

	for (int i = 0; i < N; i++) {
		if (noneed[i] == true) continue;
		outcome(i, plan[i].second);
	}

	cout << ans;
}