#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<int> num(10001, 0);
    int tmp;
    for(int i =0; i<n; i++){
        cin>>tmp;
        num[tmp]++;
    }
    for(int i =1; i<=10000; i++){
        for(int j = 1;j<=num[i]; j++){
            cout<<i<<"\n";
        }
    }
}