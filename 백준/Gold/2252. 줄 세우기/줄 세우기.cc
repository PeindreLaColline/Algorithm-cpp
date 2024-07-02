#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> g;
vector<int> indegree;

void bfs() {
    queue<int> q;

    // Initialize the queue with nodes having zero indegree
    for (int i = 1; i <= N; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    // Process nodes in topological order
    while (!q.empty()) {
        int current = q.front();  // Get the front of the queue
        q.pop();  // Remove the front element from the queue

        // Print or process the current node
        cout << current << " ";

        // Traverse through the neighbors of the current node
        for (int j = 0; j < g[current].size(); ++j) {
            int neighbor = g[current][j];

            // Decrease the indegree of the neighbor
            if (--indegree[neighbor] == 0) {
                q.push(neighbor);  // If indegree becomes zero, add to the queue
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    g.resize(N + 1);
    indegree.resize(N + 1, 0);

    int a, b;
    for (int i = 0; i < M; ++i) {
        cin >> a >> b;
        g[a].push_back(b);
        indegree[b]++;
    }

    bfs();

    return 0;
}
