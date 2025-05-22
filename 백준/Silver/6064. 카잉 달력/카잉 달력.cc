/*12:00*/
#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
    while(b != 0){
        long long temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}

int main(){
    int test;
    cin >> test;

    long long m, n, x, y;

    for(int t = 0; t<test; t++){

        cin >> m >> n >> x >> y;

        long long limit = lcm(m, n);
        long long ans = -1;

        for(long long i = x; i<=limit; i += m){
            if((i%n) == (y%n)){
                ans = i;
                break;
            }
        }
        cout << ans <<'\n';


    }
}