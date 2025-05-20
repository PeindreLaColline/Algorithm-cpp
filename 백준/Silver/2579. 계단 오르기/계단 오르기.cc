/*11:20*/
#include <iostream>
#include <vector>
using namespace std;

int main(){
    //하나 건너뛰거나
    //하나 올라가거나 -> 하나씩 올라가는 걸 연속 두 번 하면 안 됨

    int n;
    cin >> n;
    vector<long long> v(n);

    for(int i =0; i<n; i++){
        cin >> v[i];
    }

    vector<pair<int, int> > dp(n);

    dp[0].first = v[0];
    dp[0].second = 0;
    dp[1].first = v[0]+v[1];
    dp[1].second = v[1];

    for(int i =2; i<n; i++){
        dp[i].first = dp[i-1].second + v[i];
        dp[i].second = max(dp[i-2].first, dp[i-2].second) + v[i];
    }
    
    cout << max(dp[n-1].first, dp[n-1].second);
    
}