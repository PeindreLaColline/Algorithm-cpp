/*14:03*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<long long> tree;

int main(){

    cin >> n >> m;
    tree.resize(n, 0);

    for(int i =0; i<n; i++){
        cin >> tree[i];
    }

    sort(tree.begin(), tree.end(), greater<>());

    long long ans = 0;
    
    long long s = 0;
    long long e = tree[0];
    while(s<=e){
        
        long long mid = (s+e)/2;

        long long tmp = 0;
        for(int i =0; i<n; i++){
            if(tree[i] <= mid) break;
            tmp += (tree[i] - mid);
        }

        if(tmp >= m){
            ans = max(ans, mid);
            s = mid+1;
        }
        else e = mid-1;
    }

    cout << ans;

}