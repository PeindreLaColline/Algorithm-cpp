/*
* 백준 1446번
* 실버1
* 다익스트라
*/
#include <iostream>
#include <vector>
using namespace std;

#define MAX 100002

int main() {
	int N, D;
	cin >> N >> D;
	
	vector<vector<pair<int, int>>> edge(D+1);
	int start, end, weight;
	for (int i = 0; i < N; i++) {
		cin >> start >> end >> weight;
		if (end - start < weight) continue; //지름길보다 그냥 가는 게 빠른 경우 배제
		if (end > D) continue; //지름길 끝나는 곳이 D보다 먼 경우 배제
		edge[end].push_back({ start, weight }); //지름길이 끝나는 지점에 대해서 출발점을 저장
	}

	/*
	i까지 온 후 
	만약 i까지 오는 다른 지름길이 있다면 (지름길 시작점을 s라고 가정)
	i-1까지의 경로 + i 과
	s까지의 경로 + 지름길 weight
	를 비교해서 더 작은 것을
	shortcut[i]에 저장
	*/
	vector<int> shortcut(D+1);
	shortcut[0] = 0;
	int tmp = 0;
	for (int i = 1; i <= D; i++) {
		shortcut[i] = shortcut[i - 1] + 1;
		if (!edge[i].empty()) {
			for (int j = 0; j < edge[i].size(); j++) {
				if (shortcut[i] > shortcut[edge[i][j].first] + edge[i][j].second) {
					shortcut[i] = shortcut[edge[i][j].first] + edge[i][j].second;
				}
			}
		}
	}

	cout << shortcut[D];

}