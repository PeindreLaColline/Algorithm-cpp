/*01:43*/
/*
슬라이딩 윈도우
    */
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int n, k;
vector<int> v;

int main(){
    cin >> n >> k;
    v.resize(n);
    for(int i =0; i<n; i++){
        cin >> v[i];
    }

    int cur = 0;
    for(int i =0; i<k; i++){
        cur += v[i];
    }
    int ans = cur;

    for(int i =1; i<=n-k; i++){
        cur = cur-v[i-1]+v[i+k-1];
        ans = max(ans, cur);
    }

    cout << ans;

}
