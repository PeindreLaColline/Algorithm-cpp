#include <iostream>
#include <vector>
using namespace std;

vector<int> numx(26);
vector<int> numy(26);

vector<int> garo(6,0);
vector<int> sero(6,0);
int leftt = 0;
int rightt = 0;

int main() {
	int num;
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			cin >> num;
			numx[num] = j;
			numy[num] = i;
		}
	}

	int ans = 0;
	int time = 0;
	bool done = false;
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			cin >> num;
			if (done) continue;
			time++;
			
			
			garo[numx[num]]++;
			sero[numy[num]]++;
			if (numx[num] == numy[num]) rightt++;
			if (numx[num] + numy[num] == 6) leftt++;

			if (garo[numx[num]] == 5) ans++;
			if (sero[numy[num]] == 5) ans++;
			if (rightt == 5) {
				rightt = -1;
				ans++;
			}
			if (leftt == 5) {
				leftt = -1;
				ans++;
			}

			if (ans >= 3) {
				cout << time << endl;
				done = true;
			}
		}
	}
}
