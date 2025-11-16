//13:33
#include <iostream>
#include <vector>
using namespace std;

vector<int> pre;

void post(int s, int e){
    if(s>e) return;

    int root = pre[s];

    int mid = s+1;
    while(mid <= e && pre[mid]<root){
        mid++;
    }

    post(s+1, mid-1);
    post(mid, e);

    cout << root << "\n";
}

int main(){
    int x;
    while(cin >> x){
        pre.push_back(x);
    }

    post(0, pre.size()-1);
    
}