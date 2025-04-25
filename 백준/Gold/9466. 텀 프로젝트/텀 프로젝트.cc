#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
vector<bool> visited, finished;
int cnt;

void dfs(int x) {
    visited[x] = true;
    int next = v[x];
    
    if (!visited[next]) {
        dfs(next);
    } else if (!finished[next]) {
        // 사이클 발견
        for (int i = next; i != x; i = v[i]) {
            cnt++;
        }
        cnt++; // 자기 자신 포함
    }

    finished[x] = true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    
    while (T--) {
        int n;
        cin >> n;
        v = vector<int>(n + 1);
        visited = vector<bool>(n + 1, false);
        finished = vector<bool>(n + 1, false);
        cnt = 0;
        
        for (int i = 1; i <= n; ++i) {
            cin >> v[i];
        }
        
        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) dfs(i);
        }
        
        cout << n - cnt << '\n';
    }
}