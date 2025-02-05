#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> pq;
vector<pair<int, int>> point;

int main(){
    cin>>n;
    point.resize(n);

    int a, b;
    for(int i =0; i<n; i++){
        cin>>a>>b;
        point[i] = make_pair(a, b);
    }

    sort(point.begin(), point.end());

    int ans = 1;

    pq.push(point[0].second);
    for(int i =1; i<n; i++){
        while(!pq.empty() && pq.top() <= point[i].first){
            pq.pop();
        }
        pq.push(point[i].second);
        ans = max((int)pq.size(), ans);      
    }

    cout<<ans<<endl;
}