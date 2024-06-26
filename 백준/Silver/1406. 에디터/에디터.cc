#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;

	int m;
	cin >> m;

	list<char> sentence;
	auto cursor = sentence.end();
	for (int i = 0; i < s.size(); i++) {
		sentence.push_back(s[i]);
	}

	char command;
	char cha;
	for (int i = 0; i < m; i++) {
		cin >> command;
        switch (command) {
        case 'L':
            if (cursor != sentence.begin()) {
                cursor--;
            }
            break;
        case 'D':
            if (cursor != sentence.end()) {
                cursor++;
            }
            break;
        case 'B':
            if (cursor != sentence.begin()) {
                auto prev = cursor;
                cursor--;
                cursor = sentence.erase(cursor);
                cursor = prev;
            }
            break;
        case 'P':
            cin >> cha;
            sentence.insert(cursor, cha);
            break;
        default:
            break;
        }
	}
    
    for (auto it = sentence.begin(); it != sentence.end(); ++it) {
        cout << *it;
    }
}