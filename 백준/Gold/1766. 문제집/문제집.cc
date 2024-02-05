//백준1766번
//우선순위 큐, 위상정렬

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<vector<int>> node(N + 1); //node[a][b]: b보다 a를 먼저 풀어야 함
	vector<int> num(N + 1, 0); //[i]: i보다 선행되어야 할 문제들의 개수
	int a, b; //b보다 a를 먼저 풀어야 함
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		node[a].push_back(b);
		num[b]++;
	}

	priority_queue<int, vector<int>, greater<int>>pq;
	for (int i = 1; i <= N; i++) {
		if (num[i] == 0) { //i 자신보다 선행되어야하는 노드가 없는 경우
			pq.push(i); //pq에 저장
		}
	}
	
	int tmp;
	while (!pq.empty()) {
		tmp = pq.top();
		pq.pop();
		cout << tmp << " "; //pq의 top을 프린트

		for (int i = 0; i < node[tmp].size(); i++) { 
			//tmp가 smth보다 선행되어야한다고 저장되어 있음 
			//현재의 tmp에 저장된 smth의 개수만큼 반복하여 순회함
			if (--num[node[tmp][i]] == 0) {
				//smth중에서 smth보다 선행되어야할 문제가 없는 노드는
				pq.push(node[tmp][i]);//pq에 저장함
			}
		}
	}
}