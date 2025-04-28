/*14:59*/
#include <iostream>
using namespace std;

typedef long long ll;

ll A, B, C;

int main() {
    cin >> A >> B >> C;

    ll result = 1;
    A = A % C;

    while (B > 0) {
        if (B % 2 == 1) {
            result = (result * A) % C;
        }
        A = (A * A) % C;
        B /= 2;
    }

    cout << result << endl;
}