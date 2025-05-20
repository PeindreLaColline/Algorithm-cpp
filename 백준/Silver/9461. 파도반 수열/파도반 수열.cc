/*11:53*/
#include <iostream>
#include <vector>
using namespace std;

int test, n;
vector<long long> dp;
vector<int> ans;
int maxi = 0;

int main(){
    cin >> test;
    ans.resize(test);

    for(int t = 0; t<test; t++){
        cin >> ans[t];
        maxi = max(maxi, ans[t]);
    }

    dp.resize(maxi+1, 0);
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;
    dp[6] = 3;

    for(int i = 7; i<=maxi; i++){
        dp[i] = dp[i-1]+dp[i-5];
    }

    for(int i = 0; i<test; i++){
        cout << dp[ans[i]] << '\n';
    }
    
}
