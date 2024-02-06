#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int T, N, M;
	cin >> T;

	long long int a, b;
	int up, down;

	for (int test_case = 0; test_case < T; test_case++) {
		cin >> N >> M;
		
		a = 1;
		b = 1;

		up = 1;
		down = 1;

		if (M - N > N) { //M-N으로 약분
			up = M - N + 1;
			down = N;
		}
		else { //N으로 약분
			up = N + 1;
			down = M - N;
		}

		for (int i = up; i <= M; i++) {
			a *= i;
		}
		for (int i = 1; i <= down; i++) {
			b *= i;
		}

		cout << a / b << endl;
	}
}