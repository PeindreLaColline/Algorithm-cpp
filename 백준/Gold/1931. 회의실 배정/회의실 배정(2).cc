/*17:26*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int,int> > v;

bool compare(const pair<int, int> &a, const pair<int, int> &b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}

vector<int> dp;

int main(){
    cin >> n;
    v.resize(n);

    int a, b;
    for(int i =0; i<n; i++){
        cin >> a >> b;
        v[i] = make_pair(a, b);
    }

    sort(v.begin(), v.end(), compare);
    
    int ans = 1;
    int ce = v[0].second;
    int s, e;
    for(int i =1; i<n; i++){
        s = v[i].first;
        e = v[i].second;
        if(s >= ce){
            ce = e;
            ans++;
        }
    }

    cout << ans;

}
