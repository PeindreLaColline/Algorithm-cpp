/*16:15*/
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> dp(n+1, 98764321);
    dp[0] = 0;
    dp[1] = 1;

    for(int i =2; i<=n; i++){
        int j = 1;
        while(j*j <= i){
            dp[i] = min(dp[i], dp[i-j*j]+1);
            j++;
        }
    }

    cout << dp[n];
}