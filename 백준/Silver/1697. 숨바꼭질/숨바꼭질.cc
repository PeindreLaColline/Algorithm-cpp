/*21:12*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct compare{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b){
        return a.second > b.second;
    }
};
priority_queue<pair<int, int>, vector<pair<int, int> >, compare> pq;

int n, m;
vector<int> dp(100001, 987654321);

void greedy(){
    while(!pq.empty()){
        pair<int, int> cur = pq.top();
        pq.pop();

        if(cur.second != dp[cur.first]) continue;

        if(cur.first * 2 <= m * 2 && cur.first *2 <= 100001 && dp[cur.first * 2] > dp[cur.first] + 1){
            dp[cur.first * 2] = dp[cur.first] + 1;
            pq.push(make_pair(cur.first * 2, dp[cur.first *2]));
        }
        if(cur.first - 1 >= 0 && dp[cur.first -1] > dp[cur.first] +1){
            dp[cur.first -1] = dp[cur.first] +1;
            pq.push(make_pair(cur.first -1, dp[cur.first -1]));
        }
        if(cur.first + 1 <= m && dp[cur.first +1] > dp[cur.first] +1){
            dp[cur.first +1] = dp[cur.first] +1;
            pq.push(make_pair(cur.first +1, dp[cur.first +1]));
        }
    }
}

int main(){
    cin >> n >> m;
    dp[n] = 0;
    pq.push(make_pair(n, 0));

    greedy();

    cout << dp[m];
}