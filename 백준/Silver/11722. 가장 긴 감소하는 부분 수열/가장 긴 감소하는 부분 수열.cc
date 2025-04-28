/*11:33*/
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int n;
vector<int> v;
vector<int> ans;

int main(){
    cin >> n;
    v.resize(n);
    ans.resize(n, 987654321);
    int maxi = 1;
    for(int i = 0; i<n; i++){
        cin >> v[i];
    }

    for(int i = n-1; i>= 0; i--){
        for(int j =0; j<n; j++){
            if(ans[j] >= v[i]){
                ans[j] = v[i];
                maxi = max(maxi, j+1);
                break;
            }
        }
    }

    // for(int i =0; i<n; i++){
    //     cout << ans[i]<< " ";
    // }
    // cout << endl;

    cout << maxi;


}
/*
42, 7, 89, 16, 55, 3, 78, 64, 31, 97, 24, 11, 68, 85, 36, 2, 91, 50, 73, 27
8
100 7 89 16 55 3 78 64
*/