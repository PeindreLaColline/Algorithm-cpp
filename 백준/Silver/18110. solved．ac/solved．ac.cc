/*16:36*/
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    if (n == 0) {
        cout << 0;
        return 0;
    }

    sort(v.begin(), v.end());

    int num = round(n * 0.15);

    int ans = 0;
    for (int i = num; i < n - num; i++) {
        ans += v[i];
    }

    ans = round((double)ans / (n - num * 2));
    cout << ans;
}