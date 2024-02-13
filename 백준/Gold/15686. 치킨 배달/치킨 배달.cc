//백준15686 치킨 배달
//골드5
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define MAX 3000;

int N, M;

//address (x, y) of each of them
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
int house_size = 0;

vector<vector<int>> dist; //distance

int ans = MAX;

int get_distance(int x1, int x2, int y1, int y2) {
	return (abs(x1 - x2) + abs(y1 - y2));
}

void get_whole_distance(vector<bool> availability, stack<int> tmp_visited) {
	vector<int> visited(M);
	for (int i = 0; i < M; i++) {
		visited[i] = tmp_visited.top();
		tmp_visited.pop();
	}

	int cur_ans = 0;
	int shortest;
	for (int i = 0; i < house_size; i++) {
		shortest = MAX;
		for (int j = 0; j < M; j++) {
			if (dist[i][visited[j]] < shortest) shortest = dist[i][visited[j]];
		}
		cur_ans += shortest;
		if (cur_ans > ans) return;
	}
	ans = cur_ans;
}

void backtracking(vector<bool> availability, stack<int> visited, int lastest) {
	if (visited.size() == M) {
		get_whole_distance(availability, visited);
		return;
	}

	for (int i = lastest; i < availability.size(); i++) {
		if (availability[i] == true) continue;
		visited.push(i);
		availability[i] = true;
		backtracking(availability, visited, i);
		visited.pop();
		availability[i] = false;
	}
}

int main() {
	cin >> N >> M;

	//input
	int tmp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> tmp;
			if (tmp == 0) {continue;}
			else if (tmp == 1) {house.push_back({ j, i });}
			else if (tmp == 2) {chicken.push_back({ j, i });}
		}
	}
	house_size = house.size();

	//get distance for all
	dist.resize(house_size);

	for (int i = 0; i < house_size; i++) {
		for (int j = 0; j < chicken.size(); j++) {
			tmp = get_distance(house[i].first, chicken[j].first, house[i].second, chicken[j].second);
			dist[i].push_back(tmp);
		}
	}

	//backtracking
	stack<int> visited;
	vector<bool> availability(chicken.size(), false); //chicken 
	backtracking(availability, visited, 0);

	cout << ans;
}
