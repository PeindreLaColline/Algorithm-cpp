#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v;

int main(){
    cin>>n;
    v.resize(n);

    for(int i =0; i<n; i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end());

    int ans = 4;
    int cnt;
    int idx;
    for(int i =0; i<n-1; i++){
        cnt = 0;
        idx = i;
        for(int j=0; j<=4; j++){
            if(v[idx] == v[i]+j) idx++;
            else cnt++;
            if(idx >= n){
                ans = min(ans, cnt+(4-j));
                break;
            }
            if(j==4){
                ans = min(ans, cnt);
                break;
            }
        }
    }

    cout<<ans;
}