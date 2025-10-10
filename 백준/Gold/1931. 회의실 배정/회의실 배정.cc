//16:43
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int a, b;
vector<pair<int, int> > v;


bool compare(const pair<int, int> &a, const pair<int, int> &b){
        if(a.second == b.second){
            return a.first < b.first;
        }
        else return a.second < b.second;
    }

int main(){
    cin >> n;

    v.resize(n);
    for(int i =0; i<n; i++){
        cin>> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end(), compare);

    int cnt = 0;
    int end_time = 0;

    for(int i =0; i<n; i++){
        if(v[i].first >= end_time){
            cnt++;
            end_time = v[i].second;
        }
    }

    cout << cnt;
}