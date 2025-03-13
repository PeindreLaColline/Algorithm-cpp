/*14:45*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int> > v;

bool compare(const pair<int, int> &a, const pair<int, int> &b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    else{
        return a.second < b.second;
    }
}

int main(){
    cin >> n;
    v.resize(n);

    int x, y;
    for(int i =0; i<n; i++){
        cin >> x >> y;
        v[i] = make_pair(x, y);
    }

    sort(v.begin(), v.end(), compare);

    for(int i =0; i<n; i++){
        cout<<v[i].first<<" "<<v[i].second << "\n";
    }
}