/*11:23*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct block{
    int l;
    int h;
    int r;

    block(int l, int h, int r) : l(l), h(h), r(r) {}
};

struct compare{
    bool operator()(const block &a, const block &b){
        return a.h < b.h;
    }
};
priority_queue<block, vector<block>, compare> pq;

bool v_compare(const block &a, const block &b){
    return a.l < b.l;
}

int n;
vector<block> v;

int main(){
    cin >> n;
    block b = {0, 0, 0};
    v.resize(n, b);
    for(int i =0; i<n; i++){
        cin >> b.l >> b.h >> b.r;
        v[i] = b;
    }

    sort(v.begin(), v.end(), v_compare);

    int idx = 0;
    int currX = 0;
    int prevHeight = 0;
    while (idx < n || !pq.empty()) {
        if (pq.empty() || (idx < n && v[idx].l <= pq.top().r)) {
            currX = v[idx].l;
            while (idx < n && v[idx].l == currX) {
                pq.push(v[idx]);
                idx++;
            }
        } else {
            currX = pq.top().r;
            while (!pq.empty() && pq.top().r <= currX) {
                pq.pop();
            }
        }

        int currHeight = pq.empty() ? 0 : pq.top().h;
        if (currHeight != prevHeight) {
            cout << currX << " " << currHeight << " ";
            prevHeight = currHeight;
        }
    }
   
}