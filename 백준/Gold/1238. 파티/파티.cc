#include <iostream>
#include <vector>
#include <queue>
#include<cstring>
using namespace std;

#define MAX 98765432
//#define MAX 10000002 왠진 모르겠지만 이 값 쓰면 오류남 충분히 안 큰가 이게?

vector<pair<int, int>> edge[1002];
int dst[1002];
//vector<int> dst;

int N, M, X;
int result;

void shortest(int from, int to) {
	//dst.resize(N, MAX); dst를 벡터로 선언하고 이렇게 초기화 하면 값이 오류남 왜?
	memset(dst, MAX, sizeof(dst));
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, from });
	dst[from] = 0;
	int current_ind;
	int current_wei;
	int next_ind;
	int next_wei;
	while (!pq.empty()) {
		current_ind = pq.top().second; //현재 정점
		current_wei = pq.top().first; //현재 정점까지의 가중치
		pq.pop();
		if (current_ind == to) {
			result = dst[to];
			break;
		}
		for (int i = 0; i < edge[current_ind].size(); i++) {
			next_ind = edge[current_ind][i].second; //다음 정점
			next_wei = current_wei + edge[current_ind][i].first; //다음 정점까지의 가중치

			if (dst[next_ind] > next_wei) {
				dst[next_ind] = next_wei;
				pq.push({ next_wei, next_ind });
			}
		}

	}

}

int main() {
	cin >> N >> M >> X;
	X--;

	int start, end, weight;
	for (int i = 0; i < M; i++) {
		cin >> start >> end >> weight;
		edge[start - 1].push_back({ weight, end - 1 });
	}

	int ans = 0;
	int going = 0;
	int coming = 0;
	
	for (int i = 0; i < N; i++) {
		shortest(i, X);
		going = result;
		shortest(X, i);
		coming = result;
		if (ans < going + coming) ans = going + coming;
	}

	cout << ans;
}