#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int> > map;
vector<vector<vector<int> > > dp;

int main(){
    cin >> n;
    map.resize(n, vector<int>(n));
    dp.resize(n, vector<vector<int> >(n, vector<int>(3, 0)));

    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            cin >> map[i][j];
        }
    }

    dp[0][1][0] = 1;

    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            if(map[i][j] == 1) continue;

            //가로
            if(j+1 <n && map[i][j+1] != 1) dp[i][j+1][0] += dp[i][j][0];
            if(j+1 <n && i+1<n && map[i][j+1] != 1 && map[i+1][j] != 1 && map[i+1][j+1] != 1) dp[i+1][j+1][2] += dp[i][j][0];

            //세로
            if(i+1<n && map[i+1][j] != 1) dp[i+1][j][1] += dp[i][j][1];
            if(j+1 <n && i+1<n && map[i][j+1] != 1 && map[i+1][j] != 1 && map[i+1][j+1] != 1) dp[i+1][j+1][2] += dp[i][j][1];

            //대각선
            if(j+1<n && map[i][j+1] != 1) dp[i][j+1][0] += dp[i][j][2];
            if(i+1<n && map[i+1][j] != 1) dp[i+1][j][1] += dp[i][j][2];
            if(i+1<n && j+1<n && map[i][j+1]!=1 && map[i+1][j] != 1 && map[i+1][j+1] != 1) dp[i+1][j+1][2] += dp[i][j][2];
        }
    }

    cout << dp[n-1][n-1][0] + dp[n-1][n-1][1] + dp[n-1][n-1][2];
}