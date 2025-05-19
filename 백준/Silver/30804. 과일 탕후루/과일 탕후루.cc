/*11:37*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int n;
vector<int> v;
map<int, int> cnt;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    v.resize(n);
    for(int i =0; i<n; i++){
        cin >> v[i];
    }

    int left = 0, right = 0;
    int ans = 0;

    while(right < n){
        cnt[v[right]]++;

        while(cnt.size() > 2){
            cnt[v[left]]--;
            if(cnt[v[left]] == 0){
                cnt.erase(v[left]);
            }
            left++;
        }
        ans = max(ans, right-left +1);
        right++;
    }

    cout << ans;

    return 0;
}