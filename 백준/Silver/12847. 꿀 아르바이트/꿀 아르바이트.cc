/*15:11*/
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v;

int main(){
    cin >> n >> m;
    v.resize(n);
    for(int i =0; i<n; i++){
        cin >>v[i];
    }

    long long tmp = 0;
    for(int i =0; i<m; i++){
        tmp += v[i];
    }
    long long ans = tmp;
    for(int i =1; i<=n-m; i++){
        tmp -= v[i-1];
        tmp += v[i+m-1];
        if(ans < tmp) ans = tmp;
    }
    cout<<ans;

}