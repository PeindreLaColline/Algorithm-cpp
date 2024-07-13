#include <iostream>
using namespace std;

int main() {
	int cnt;
	cin >> cnt;

	int yes = 2; 
	int no = 1;
	int y, n;
	for (int i = 1; i < cnt; i++) {
		y = yes; n = no;
		yes = (y + n * 2) % 9901; 
		no = (y + n) % 9901;
	}
	cout << (yes + no) % 9901;
}