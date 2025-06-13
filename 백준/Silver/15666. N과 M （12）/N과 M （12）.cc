/*12:13*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v(10001, 0);
vector<int> num;

int n, m;

void dfs(vector<int> ans, int pre, int idx){
    ans.push_back(pre);
    if(ans.size() == m){
        for(int i =0; i<m; i++){
            cout << ans[i] <<" ";
        }
        cout << '\n';
        return;
    }

    for(int i =idx; i<num.size(); i++){
        int cur = num[i];
        dfs(ans, cur, i);
    }

}

int main(){
    
    cin >> n >> m;

    int tmp;
    for(int i = 0; i<n; i++){
        cin >> tmp;
        if(v[tmp] == 0) num.push_back(tmp);
        v[tmp]++;
    }

    sort(num.begin(), num.end(), less<>());

    for(int i =0; i<num.size(); i++){
        dfs(vector<int>(), num[i], i);
    }
}