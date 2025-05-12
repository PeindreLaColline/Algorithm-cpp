/*16:57*/
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<int> dp(n+1, 987654321);

    dp[1] = 0;

    for(int i =2; i<=n; i++){
        if(i%6 == 0) dp[i] = min(dp[i/3]+1, dp[i/2]+1);
        else if(i%3 ==0) dp[i] = dp[i/3] +1;
        else if(i%2 == 0) dp[i] = dp[i/2] +1;
        
        int j = 1;
        while(j<i){
            if(dp[i-j] + j <= dp[i]){
                dp[i] = dp[i-j] + j;
            }
            else break;
            j++;
        }
    }

    cout << dp[n];
}