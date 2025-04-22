#include <iostream>
#include <vector>
using namespace std;

#define ll long long

ll n, t;

bool check(vector<ll> v, int dif){
    ll ans=0;

    for(ll i =1; i<n; i++){
        if(v[i]-v[i-1] > dif){
            ans += (v[i] - (v[i-1] + dif));
            v[i] = v[i-1] + dif;
        }
    }

    for(ll i = n-1; i>=1; i--){
        if(v[i-1]-v[i] > dif){
            ans += (v[i-1] - (v[i] + dif));
            v[i-1] = v[i] + dif;
        }
    }

    if(ans <= t) return true;
    else return false;
}

int main(){
    cin>>n>>t;
    vector<ll> v(n);
    for(ll i =0; i<n; i++){
        cin>>v[i];
    }

    ll s=0;
    ll e=2e9;
    ll ans = 0;

    while(s<=e){
        ll mid = (s+e)/2;

        if(check(v, mid)){
            ans = mid;
            e = mid -1;
        }
        else {
            s = mid +1;
        }
    }

    for(ll i =1; i<n; i++){
        if(v[i]-v[i-1] > ans){
            v[i] = v[i-1] + ans;
        }
    }

    for(ll i = n-1; i>=1; i--){
        if(v[i-1]-v[i] > ans){
            v[i-1] = v[i] + ans;
        }
    }

    for(ll i =0; i<n; i++){
        cout<<v[i]<<" ";
    }
}
