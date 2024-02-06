//백준14501
//브루트포스
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 15

int N;
int ans = 0;
vector<pair<int, int>> plan(MAX); //<소요 시간, 임금>
vector<bool> noneed(MAX, false); //N이 10인데, 9일차에 3일 걸리는 일이 들어오면 못함 그것들 true로 저장하는 벡터

void outcome(int start, int cur_ans) {
	if (ans < cur_ans) ans = cur_ans;

	queue<int> togo;
	for (int i = start + plan[start].first; i < N; i++) {
		if (noneed[i] == true) continue;
		else togo.push(i); //갈 수 있는 노드들 queue에 저장
	}

	int tmp;
	while (!togo.empty()) {
		tmp = togo.front();
		togo.pop();
		outcome(tmp, cur_ans + plan[tmp].second); //queue에서 하나씩 지워가며 방문함
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
