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

    int amt = n-k;

    int M = 0;
    int m = 100000000;
    int ans = M+m;
    for(int i =0; i<amt-1; i++){
        pq.push(make_pair(i, abs(v[i+1]-v[i])));
    }

    for(int i =0; i <= n-amt; i++){
        pq.push(make_pair(i+amt-2, abs(v[i+amt-1]-v[i+amt-2])));
        M = abs(v[i+amt-1]-v[i]);
        m = get_min(i);
        ans = min(ans, M+m);
    }

    cout<<ans<<endl;
}