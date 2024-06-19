#include <iostream>
#include <vector>
using namespace std;

int n;
vector<bool> v;

int pn; //people num

void woman(int num) {
	int cs = num;
	int ce = num;
	while (true) {
		if (cs <= 0 || ce > n) {
			cs++;
			ce--;
			break;
		}
		if (v[cs] == v[ce]) {
			cs--;
			ce++;
			continue;
		}
		else {
			cs++;
			ce--;
			break;
		}
	}
	if (cs >= ce) v[num] = !v[num];
	else {
		for (int i = cs; i <= ce; i++) {
			v[i] = !v[i];
		}
	}
	
}

void man(int idx) {
	if (idx == 0) {
		v[0] = !v[0];
		return;
	}
	int i = 1;
	while (true) {
		if (idx * i > n) break;
		v[idx*i] = !v[idx*i];
		i++;
	}
}

int main() {
	cin >> n;
	v.resize(n+1);
	int tmp;
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		v[i] = (tmp == 1);
	}

	cin >> pn;
	int gen, num;
	for (int i = 0; i < pn; i++) {
		cin >> gen >> num;
		if (gen == 1) man(num);
		else woman(num);
	}

	for (int i = 1; i <= n; i++) {
		cout << v[i];
		if (i == n) break;
		else if (i % 20 == 0) cout << endl;
		else cout << " ";
	}
}