/*14:55*/
#include <iostream>
using namespace std;

int main(){
    long long n, k;
    cin >> n >> k;

    long long a=1;
    long long b=1;
    long long c=1;
    for(int i =1; i<=n; i++){
        a *= i;
    }
    for(int i =1; i<=k; i++){
        b *= i;
    }
    for(int i =1; i<=(n-k); i++){
        c *= i;
    }
    cout << (a / b) / c;
}