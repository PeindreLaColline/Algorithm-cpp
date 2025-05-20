/*12:18*/
#include <iostream>
#include <vector>
using namespace std;

int n;


int main(){
    cin >> n;
    

    //first 해당칸에 세로를 넣고싶은 경우
    //second 해당칸에 가로를 넣고싶은 경우 (가로는 나보다 하나 왼쪽으로 넣는다 가정)
    //dp.resize(n);
    //vector<pair<long long, long long> > dp;
    // dp[0].first = 1;
    // dp[0].second = 0;
    // dp[1].first = 1;
    // dp[1].second = 1;

    // for(int i = 2; i<n; i++){
    //     dp[i].first = (dp[i-1].first + dp[i-1].second)%10007;
    //     dp[i].second = (dp[i-2].first + dp[i-2].second)%10007;
    // }

    // cout << (dp[n-1].first + dp[n-1].second)%10007;

    vector<int> dp(n, 0);
    dp[0] = 1;
    dp[1] = 2;
    for(int i =2; i<n; i++){
        dp[i] = (dp[i-1] + dp[i-2])%10007;
    }

    cout << dp[n-1];
    

    return 0;
}