/*15:58*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct po{
    int num;
    int idx;
    int order;
    
    po() : num(0), idx(0), order(0) {}
    po(int n, int i, int o) : num(n), idx(i), order(o) {}
};

bool sort_by_num(const po &a, const po &b){
    return a.num < b.num;
}

bool sort_by_idx(const po &a, const po &b){
    return a.idx < b.idx;
}

int n;
vector<po> v;

int main(){
    cin >> n;
    v.resize(n);

    int tmp;
    for(int i =0; i<n; i++){
        cin >> tmp;
        v[i] = po(tmp, i, -1);
    }

    sort(v.begin(), v.end(), sort_by_num);

    int order = 0;
    v[0].order = 0;
    for(int i =1; i<n; i++){
        if(v[i].num != v[i-1].num) order++;
        v[i].order = order;
    }

    sort(v.begin(), v.end(), sort_by_idx);

    for(int i = 0; i<n-1; i++){
        cout << v[i].order <<" ";
    }
    cout << v[n-1].order;
}
