/*12:13*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v(10001, 0);
vector<int> num;

int n, m;

void dfs(vector<int> ans, int pre){
    ans.push_back(pre);
    if(ans.size() == m){
        for(int i =0; i<m; i++){
            cout << ans[i] <<" ";
        }
        cout << '\n';
        return;
    }

    vector<bool> visited(num.size(), false);

    for(int i =0; i<num.size(); i++){
        int cur = num[i];
        if(!visited[i] && v[cur] > 0){
            v[cur]--;
            //visited[i] = true;

            dfs(ans, cur);

            v[cur]++;
        }
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
        v[num[i]]--;
        dfs(vector<int>(), num[i]);
        v[num[i]]++;
    }
}