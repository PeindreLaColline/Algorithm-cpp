#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
	int T;
	cin >> T;
	string s;

	for (int t = 0; t < T; t++) {
		cin >> s;
		list<char> l;

		auto cursor = l.end();
		char command;
		for (int i = 0; i < s.size(); i++) {
			command = s[i];
			switch (command) {
			case '<':
				if (cursor != l.begin()) cursor--;
				break;
			case'>':
				if (cursor != l.end()) cursor++;
				break;
			case'-':
				if (cursor != l.begin()) {
					auto prev = cursor;
					cursor--;
					cursor = l.erase(cursor);
					cursor = prev;
				}
				break;
			default:
				l.insert(cursor, command);
				break;
			}
		}

		for (auto it = l.begin(); it != l.end(); ++it) cout << *it;
		cout << endl;
	}
}