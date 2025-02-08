#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

struct cmp {
    bool operator()(pair<int, int> &a, pair<int, int> &b){
        return a.second > b.second;
    }
};

int n, k;
vector<int> v;
priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> pq;

int get_min(int idx){
    while(!pq.empty()){
        if(pq.top().first < idx) pq.pop();
        else return pq.top().second;
    }
}

int main(){
    cin>>n>>k;

    v.resize(n);
    for(int i =0; i<n; i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end());

    for(int i =0; i<k-1; i++){
        pq.push(make_pair(i, abs(v[i+1]-v[i])));
    }
    int M = abs(v[(n-k)-1]-v[0]);
    int m = pq.top().second;
    int ans = M+m;
    
    for(int i =1; i<n-k-1; i++){
        pq.push(make_pair(i+(n-k)-2, abs(v[i+(n-k)-1]-v[i+(n-k)-2])));
        M = abs(v[i+(n-k)-1]-v[i]);
        m = get_min(i);
        ans = min(ans, M+m);
    }

    cout<<ans<<endl;
}
