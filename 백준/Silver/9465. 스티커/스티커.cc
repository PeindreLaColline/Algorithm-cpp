/*15:08*/
#include <iostream>
#include <vector>
using namespace std;

int test;
int n;
vector<vector<int> > v;
vector<vector<int> > dp;

int main(){
    cin >> test;
    for(int t = 0; t<test; t++){
        cin >> n;
        
        v.clear();
        dp.clear();

        v.resize(2, vector<int>(n, 0));
        dp.resize(3, vector<int>(n, 0));
        
        for(int i =0; i<2; i++){
            for(int j = 0; j<n; j++){
                cin >> v[i][j];
            }
        }

        dp[0][0] = v[0][0];
        dp[1][0] = v[1][0];
        dp[2][0] = 0;

        int fir = dp[0][0];
        int sec = dp[1][0];
        int non = dp[2][0];

        for(int i =1; i<n; i++){
            dp[0][i] = max(non + v[0][i], sec + v[0][i]);
            dp[1][i] = max(non + v[1][i], fir + v[1][i]);
            dp[2][i] = max(fir, sec);

            fir = dp[0][i];
            sec = dp[1][i];
            non = dp[2][i];
        }

        cout << max(dp[0][n-1], max(dp[1][n-1], dp[2][n-1])) << endl;
    }

    
}