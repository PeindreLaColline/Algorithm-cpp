/*15:12*/
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int n;
vector<long long> v;

int main(){
    cin >> n;
    v.resize(n);
    for(int i =0; i<n; i++){
        cin >> v[i];
    }

    long long ans = 9876543210;
    int a, b;
    int p1 = 0;
    int p2 = n-1;
    while(p1<p2){
        if(abs(ans) > abs(v[p1] + v[p2])){
            a = v[p1];
            b = v[p2];
            ans = v[p1] + v[p2];
        }
        if(v[p1] + v[p2]<0){
            p1++;
        }
        else if(v[p1] + v[p2] > 0){
            p2--;
        }
        else{
            break;
        }
    }

    cout << a << " " << b;
}