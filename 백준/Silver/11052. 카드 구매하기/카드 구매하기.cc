/*12:18*/
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> dp;

int main(){
    cin >> n;
    dp.resize(n+1, 0);
    for(int i =1; i<=n; i++){
        cin >> dp[i];
    }

    for(int i =2; i<=n; i++){
        int s = 0;
        int e = i;
        while(s<=e){
            dp[i] = max(dp[i], dp[s]+dp[e]);
            s++;
            e--;
        }
    }

    cout << dp[n];
    
}