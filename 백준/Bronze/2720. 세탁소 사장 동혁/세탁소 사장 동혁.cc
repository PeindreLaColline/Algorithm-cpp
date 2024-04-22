#include <iostream>
#include <vector>
using namespace std;

int change;

vector<int> coin(4);
vector<int> ccha(4, 0); //current change
vector<int> bcha(4, 0); // best change
int bcn = 98765432; //best change number

/*
cn: 현재 사용된 코인 개수
idx: 현재 사용하고 있는 코인의 인덱스
cnum: 현재까지 계산된 거스름돈
*/
void greedy(int cn, int idx, int cnum) {
	if (bcn < cn) return;
	if (cnum < 0) return;
	if (cnum == 0) {
		if (bcn > cn) {
			bcn = cn;
			bcha = ccha;
		}
		return;
	}
	if (idx == -1) return;

	int i = 1;
	while (true) {
		if (cnum - coin[idx] * i >= 0) {
			i++;
		}
		else {
			break;
		}
	}
	
	i--;
	ccha[idx] = i;
	greedy(cn + i, idx - 1, cnum - coin[idx] * i);
}

int main() {
	int test;
	cin >> test;
	
	coin[3] = 25; //Q
	coin[2] = 10; //D
	coin[1] = 5; //N
	coin[0] = 1; //P

	for (int t = 0; t < test; t++) {
		cin >> change;

		//init
		ccha[0] = 0;
		ccha[1] = 0;
		ccha[2] = 0;
		ccha[3] = 0;
		bcha = ccha; 

		bcn = 98765432;

		greedy(0, 3, change);
		for (int i = 3; i >=0; i--) {
			cout << bcha[i] << " ";
		}
		cout << endl;
	}
}