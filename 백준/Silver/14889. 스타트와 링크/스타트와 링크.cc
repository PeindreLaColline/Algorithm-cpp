#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int> > v;
vector<bool> visited;
int ans = 98765432;

void brute(int idx, int cnt){
    if(n/2 == cnt){
        vector<int> t1;
        vector<int> t2;
        
        for(int i =0; i<n; i++){
            if(visited[i]){
                t1.push_back(i);
            }
            else{
                t2.push_back(i);
            }
        }

        int score1 = 0;
        int score2 = 0;
        for(int i =0; i<n/2; i++){
            for(int j = 0; j<n/2; j++){
                score1 += v[t1[i]][t1[j]];
                score2 += v[t2[i]][t2[j]];
            }
        }

        if(abs(score1 - score2) < ans) ans = abs(score1 - score2);
        return;
    }
    for(int i = idx; i<n; i++){
        if(visited[i]) continue;
        else{
            visited[i] = true;
            brute(i+1, cnt+1);
            visited[i] = false;
        }
        
    }
}

int main(){
    cin >> n;
    vector<int> tmp(n);
    v.resize(n, tmp);
    visited.resize(n);
    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            cin >> v[i][j];
        }
    }

    brute(0, 0);
    cout << ans;
}