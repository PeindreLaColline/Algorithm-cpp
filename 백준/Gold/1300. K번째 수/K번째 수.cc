/*12:24*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

long long n, k;

int main(){
    cin >> n >> k;
    
    long long s = 1;
    long long e = n *n;
    long long ans = 0;

    while( s<= e){
        long long mid = (s+e)/2;

        long long cnt = 0;

        for(long long i = 1; i <= n; i++){
            cnt += min(mid/i, n);
        }

        if( cnt >= k){
            ans = mid;
            e = mid -1;
        }
        else{
            s = mid +1;
        }

    }

    cout << ans;
}