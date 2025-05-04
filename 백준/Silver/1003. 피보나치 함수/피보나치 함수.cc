/*16:47*/
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int> > dp;

int main(){

    int test;
    cin >> test;

    for(int t = 0; t<test; t++){
        cin >> n;
        
        dp.clear();
        dp.resize(2, vector<int>(n+1, 0));

        dp[0][0] = 1;
        dp[1][0] = 0;

        if(n>=1){
            dp[0][1] = 0;
            dp[1][1] = 1;
            
            if(n>=2){
                dp[0][2] = 1;
                dp[1][2] = 1;
            }
        }
        

        for(int i =3; i<=n; i++){
            dp[0][i] = dp[0][i-1] + dp[0][i-2];
            dp[1][i] = dp[1][i-1] + dp[1][i-2];
        }

        cout << dp[0][n] << " " << dp[1][n] << "\n";


    }

}