//8:37
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int n;
vector<vector<int> > color;
vector<vector<int> > dp;

int main(){
    cin >> n;
    color.resize(n, vector<int>(3));
    dp.resize(n, vector<int>(3));

    for(int i =0; i<n; i++){
        for(int j = 0; j<3; j++){
            cin >> color[i][j];
        }
    }

    dp[0][0] = color[0][0];
    dp[0][1] = color[0][1];
    dp[0][2] = color[0][2];

    for(int i =1; i<n; i++){
        dp[i][0] = color[i][0] + min(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = color[i][1] + min(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = color[i][2] + min(dp[i-1][0], dp[i-1][1]);
    }

    cout << min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));

}