/*13:41*/
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int n, m, k;
vector<vector<int> > v;
int ans = 987654321;

void oper_sero(int x){
    queue<int> q;
    int cur = 0;
    for(int i = 0; i<k; i++){
        int cnt = 0;
        for(int j = x; j<x+k; j++){
            cnt += v[i][j];
        }
        cur += cnt;
        q.push(cnt);
    }
    ans = min(ans, min(cur, abs(k*k -cur)));

    for(int i=1; i<=n-k; i++){
        
        int cnt = 0;
        for(int j = x; j<x+k; j++){
            cnt += v[i+k-1][j];
        }
        cur -= q.front();
        q.pop();
        cur += cnt;
        q.push(cnt);
        ans = min(ans, min(cur, abs(k*k -cur)));
    }
    
}

void oper_garo(){
    for(int i =0; i<=m-k; i++){
         oper_sero(i);
    }
 }

int main(){
    cin >> n >> m >> k;

    string s;
    v.resize(n, vector<int> (m));
    for(int i =0; i<n; i++){
        cin >> s;
        for(int j=0; j<m; j++){
            //왼쪽위가 검은색일 때 기준
            if(i%2 == 0){
                if(j%2 == 0){
                    if(s[j] == 'B') v[i][j] = 0;
                    else v[i][j] = 1;
                }
                else{
                    if(s[j] == 'B') v[i][j] = 1;
                    else v[i][j] = 0;
                }
            }
            else{
                if(j%2 == 0){
                    if(s[j] == 'B') v[i][j] = 1;
                    else v[i][j] = 0;
                }
                else{
                    if(s[j] == 'B') v[i][j] = 0;
                    else v[i][j] = 1;
                }
            }
        }
    }

    oper_garo();

    cout << ans;
}