/*15:58*/
#include <iostream>
#include <climits>
using namespace std;

int main(){
    long long x, y;
    cin >> x >> y;
    long long z = (100 * y) / x;

    if(z >= 99){
        cout << -1 <<endl;
    }
    else{
        long long s = 1;
        long long e = 1000000000;
        long long mid, tmp;
        while(s<=e){
            mid = (s+e)/2;
            tmp = (100 * (y + mid)) / (x+mid);
            if(tmp <= z){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        cout<< s << endl;
    }

}