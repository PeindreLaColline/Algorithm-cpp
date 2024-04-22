#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string s;
	cin >> s;

	/*
	1: A
	2: B
	3: .
	*/
	vector<int> arr;

	bool poss = true;

	int tmp = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'X') {
			tmp++;
		}
		else if (s[i] == '.') {
			if (tmp % 2 != 0) {
				poss = false;
				break;
			}
			while (true) {
				if (tmp == 0) break;
				if (tmp - 4 >= 0) {
					arr.push_back(1);
					tmp -= 4;
				}
				else if (tmp - 2 >= 0) {
					arr.push_back(2);
					tmp -= 2;
				}
			}
			arr.push_back(3);
		}
	}
	
	if (tmp) {
		if (tmp % 2 != 0) {
			poss = false;
		}
		else {
			while (true) {
				if (tmp == 0) break;
				if (tmp - 4 >= 0) {
					arr.push_back(1);
					tmp -= 4;
				}
				else if (tmp - 2 >= 0) {
					arr.push_back(2);
					tmp -= 2;
				}
			}
		}
	}

	if (poss) {
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i] == 1) cout << "AAAA";
			else if (arr[i] == 2) cout << "BB";
			else if (arr[i] == 3) cout << ".";
		}
	}
	else {
		cout << -1;
	}
}