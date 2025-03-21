/*15:41*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main(){
    int n;
    vector<double> v;
    cin>>n;
    v.resize(n);
    for(int i =0; i<n; i++){
        cin >> v[i];
    }

    double maxi = *max_element(v.begin(), v.end());
    double ans = 0;
    for(int i =0; i<n; i++){
        ans += (v[i]*100)/maxi;
    }
    ans/=n;
    
    cout <<  ans;
}