#include <iostream>
#include <vector>
using namespace std;

int n;
vector<pair<int,int>> tree;

void pre_tree(int cur) {
	cout << char(cur + int('A'));
	if (tree[cur].first != -1) {
		pre_tree(tree[cur].first);
	}
	if (tree[cur].second != -1) {
		pre_tree(tree[cur].second);
	}
}

void in_tree(int cur) {
	if (tree[cur].first != -1) {
		in_tree(tree[cur].first);
	}
	cout << char(cur + int('A'));
	if (tree[cur].second != -1) {
		in_tree(tree[cur].second);
	}
}

void post_tree(int cur) {
	if (tree[cur].first != -1) {
		post_tree(tree[cur].first);
	}
	if (tree[cur].second != -1) {
		post_tree(tree[cur].second);
	}
	cout << char(cur + int('A'));
}

int main() {
	cin >> n;
	pair<int, int> tmp = { -1, -1 };
	tree.resize(n, tmp);

	char p, c1, c2;
	for (int i = 0; i < n; i++) {
		cin >> p >> c1 >> c2;
		if (c1 != '.') {
			tree[int(p - 'A')].first = int(c1 - 'A');
		}
		if (c2 != '.') {
			tree[int(p - 'A')].second = int(c2 - 'A');
		}
	}

	pre_tree(0);
	cout << endl;
	in_tree(0);
	cout << endl;
	post_tree(0);
}