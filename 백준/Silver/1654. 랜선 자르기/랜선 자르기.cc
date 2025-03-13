/*14:53*/
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int k, n;
vector<int> v;

int main(){
    cin >> k >> n;
    v.resize(k);
    for(int i=0; i<k; i++){
        cin >> v[i];
    }

    long long s = 1;
    long long e = *max_element(v.begin(), v.end());
    long long mid;
    long long ans = 0;
    while(s<=e){
        mid = (s+e)/2;
        long long tmp = 0;
        for(int i =0; i<k; i++){
            tmp += v[i]/mid;
        }

        if(tmp < n) e = mid-1;
        else{
            s = mid +1;
            ans = mid;
        }
    }

    cout<<ans;
}