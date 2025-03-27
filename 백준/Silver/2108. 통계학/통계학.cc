/*15:51*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

int n;
vector<int> v;

struct compare{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b){
        if(a.second == b.second){
            return a.first > b.first;
        }
        return a.second < b.second;
    }
};

int main(){
    cin >> n;
    v.resize(n);
    for(int i =0; i<n; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int ans1 = v[0];
    priority_queue<pair<int, int>, vector<pair<int, int> >, compare> pq;
    int cnt = 1;
    pq.push(make_pair(v[0], cnt));
    
    for(int i = 1; i<n; i++){
        ans1 += v[i];
        if(v[i] == v[i-1]){
            cnt++;
            pq.push(make_pair(v[i], cnt));
        }
        else{
            cnt = 1;
            pq.push(make_pair(v[i], cnt));
        }
        
    }

    // while(!pq.empty()){
    //     cout << pq.top().first << " " << pq.top().second << endl;
    //     pq.pop();
    // }
    
    ans1 = round((double)ans1 / (double)n);
    if(ans1 == -0){
        cout << 0 << endl;
    }
    else{
        cout << ans1 << endl;
    }
    cout << v[n/2] << endl;
    if(pq.size() >= 2){
        pair<int, int> a = pq.top();
        pq.pop();
        pair<int, int> b = pq.top();
        if(a.second == b.second){
            cout << b.first << endl;
        }
        else{
            cout << a.first << endl;
        }
    }
    else{
        cout << pq.top().first << endl;
    }
    cout << v[n-1] - v[0] << endl;

}