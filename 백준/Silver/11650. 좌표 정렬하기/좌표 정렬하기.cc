/*16:17*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int> > v;

bool compare(const pair<int, int> &a, const pair<int, int> &b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    else return a.first < b.first;
}

int main(){
    cin >> n;
    v.resize(n);
    for(int i =0; i<n; i++){
        cin >> v[i].first;
        cin >> v[i].second;
    }
    sort(v.begin(), v.end(), compare);

    for(int i =0; i<n; i++){
        cout << v[i].first << " " << v[i].second << "\n";
    }
}