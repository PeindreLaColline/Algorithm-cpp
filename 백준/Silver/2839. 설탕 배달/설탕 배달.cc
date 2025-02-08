#include <iostream>
using namespace std;

int N;
int ans;

int main() {
	int N;
	cin >> N;

	int f = N / 5;
	while (f>=0) {
		if ((N - (f * 5)) % 3 == 0) {
			cout << f + (N - (f * 5)) / 3 << endl;
			break;
		}
		f--;
	}
	if (f == -1) cout << -1 << endl;
}