#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> map;
vector<vector<int>> dis;
vector<pair<int, int>> house;
vector<pair<int, int>> resto;
vector<int> chosen;
int ans = 98765432;

int rs;
int hs;

int get_ans() {
	int cur_sum = 0;
	int bes_num;
	int tmp;
	for (int i = 0; i < hs; i++) {
		bes_num = 98765432;
		for (int j = 0; j < m; j++) {
			tmp = dis[i][chosen[j]];
			if (tmp < bes_num) bes_num = dis[i][chosen[j]];
		}
		cur_sum += bes_num;
	}
	return cur_sum;
}

void choose_resto(int cnt, int start) {
	if (cnt == m) {
		int tmp = get_ans();
		if (tmp < ans) ans = tmp;
		return;
	}

	for (int i = start; i < rs; i++) {
		chosen[cnt] = i;
		choose_resto(cnt + 1, i + 1);
	}
}

void get_dis() {
	vector<int> vtmp(resto.size());
	for (int i = 0; i < hs; i++) {
		dis.push_back(vtmp);
		for (int j = 0; j < rs; j++) {
			dis[i][j] = abs(house[i].first - resto[j].first) + abs(house[i].second - resto[j].second);
		}
	}
}

int main() {
	cin >> n >> m;
	vector<int> vtmp(n);
	chosen.resize(m);
	int tmp;
	for (int i = 0; i < n; i++) {
		map.push_back(vtmp);
		for (int j = 0; j < n; j++) {
			cin >> tmp;
			map[i][j] = tmp;
			if (tmp == 1) house.push_back({ i, j });
			else if(tmp == 2) resto.push_back({ i, j });
		}
	}

	rs = resto.size();
	hs = house.size();

	get_dis();
	choose_resto(0, 0);

	cout << ans;
}
