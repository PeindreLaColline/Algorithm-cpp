/*21:49*/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

#define MOD 1234567891
#define R 31
#define ll long long

int n;
string s;

int main(){
    cin >> n;
    cin >> s;

    ll ans = 0;
    ll mul = 1;
    for(int i =0; i<s.size(); i++){
        ans += ((s[i] -'a' + 1) * mul) % MOD;
        ans %= MOD;
        mul = (mul * R) % MOD;
    }

    cout<<ans;

}