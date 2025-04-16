/*01:27*/
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> num(n);
    for(int i =0; i<n; i++){
        cin >> num[i];
    }

    vector<bool> v(1001, false);
    for(int i = 2; i<=1000; i++){
        if(!v[i]){
            int j = 2;
            while(i*j <= 1000){
                v[i*j] = true;
                j++;
            }
        }
    }

    int ans = 0;
    for(int i =0; i<n; i++){
        if(num[i] <= 1) continue;
        if(!v[num[i]]) ans++;
    }
    cout << ans;
}