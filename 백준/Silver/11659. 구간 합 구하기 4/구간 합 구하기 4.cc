/*14:19*/
#include <iostream>
#include <vector>
using namespace std;

int n, m;
int a, b;
vector<int> v;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    v.resize(n+1, 0);
    
    for(int i =1; i<=n; i++){
        cin >> v[i];
        v[i] += v[i-1];
    }

    for(int t = 0; t<m; t++){
        cin >> a >> b;
        cout << v[b] - v[a-1] <<"\n";
    }

}