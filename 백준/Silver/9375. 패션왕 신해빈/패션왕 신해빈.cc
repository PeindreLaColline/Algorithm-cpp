/*14:29*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int test_case;
int n;
vector<pair<string, string> > v;
vector<int> clothes;

bool compare(const pair<string, string> &a, const pair<string, string> &b){
    return a.second>b.second;
}

int main(){
    cin >> test_case;
    for(int t = 0; t<test_case; t++){
        cin >> n;
        if(n==0){
            cout << 0 << endl;
            continue;
        }
        
        v.clear();
        v.resize(n);
        clothes.clear();
        clothes.resize(1, 0);

        for(int i =0; i<n; i++){
            cin >> v[i].first >> v[i].second;
        }

        sort(v.begin(), v.end(), compare);

        string tmp = v[0].second;
        int idx = 0;
        clothes[idx]++;
        for(int i =1; i<n; i++){
            if(tmp == v[i].second){
                clothes[idx]++;
            }
            else{
                clothes.push_back(0);
                idx++;
                clothes[idx]++;
                tmp = v[i].second;
            }
        }

        int ans = 1;
        for(int i =0; i<clothes.size(); i++){
            ans *= (clothes[i]+1);
        }
        cout << --ans << endl;

    }
}