#include <iostream>
#include <vector>
using namespace std;

#define MOD 1000000000

int n;
vector<vector<int> > dp;

int main(){
    cin >> n;
    vector<int> tmp(10);
    dp.resize(n+1, tmp);

    for(int i =1; i<=9; i++){
        dp[1][i] = 1;
    }

    for(int i =2; i<=n; i++){
        dp[i][0] = dp[i-1][1] % MOD;

        for(int j = 1; j<=8; j++){
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % MOD;
        }

        dp[i][9] = dp[i-1][8] % MOD;
    }

    long long ans = 0;
    for(int i =0; i<=9; i++){
        ans = (ans + dp[n][i]) % MOD;
    }

    cout << ans;
}