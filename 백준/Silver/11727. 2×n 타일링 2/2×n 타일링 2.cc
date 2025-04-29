/*14:43*/
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<vector<int> > dp(2, vector<int>(n));

    dp[0][0] = 0; //정사각형 및 가로
    dp[1][0] = 1; //세로

    dp[0][1] = 2;
    dp[1][1] = 1;
    for(int i =2; i<n; i++){
        dp[0][i] = (dp[0][i-2] + dp[1][i-2])*2 % 10007;
        dp[1][i] = (dp[0][i-1] + dp[1][i-1]) % 10007;
    }

    cout << (dp[0][n-1] + dp[1][n-1]) % 10007;
}