/*14:34*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<int> lad(101, 0);
vector<int> sna(101, 0);
vector<int> dp(101, 98765432);

struct compare{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b){
        if(a.second == b.second){
            return a.first > b.first;
        }
        return a.second < b.second;
    }
};
priority_queue<pair<int, int>, vector<pair<int, int> >, compare> pq;

int main(){

    cin >> n >> m;

    int a, b;
    for(int i =0; i<n; i++){
        cin >> a >> b;
        lad[a] = b;
    }

    for(int i =0; i<m; i++){
        cin >> a >> b;
        sna[a] = b;
    }

    for(int i = 2; i<=7; i++){
        dp[i] = 1;
        pq.push(make_pair(i, 1));
    }

    int cur, nex, val;
    while(!pq.empty()){
        cur = pq.top().first;
        val = pq.top().second;
        pq.pop();

        if(val != dp[cur]) continue;

        if(sna[cur] != 0) nex = sna[cur];
        else if(lad[cur] != 0) nex = lad[cur];
        else{
            for(int i =1; i<=6; i++){
                nex = cur+i;
                if(nex >= 100) nex = 100;
                if(dp[nex] > dp[cur]+1){
                    dp[nex] = dp[cur]+1;
                    pq.push(make_pair(nex, dp[nex]));
                }

            }
            continue;
        }
        
        if(dp[nex] > dp[cur]){
            dp[nex] = dp[cur];
            pq.push(make_pair(nex, dp[nex]));
        }

    }

    cout << dp[100];

}