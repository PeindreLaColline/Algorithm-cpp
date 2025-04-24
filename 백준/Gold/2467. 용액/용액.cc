#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i =0; i<n; i++){
        cin >> v[i];
    }

    int a = 0;
    int b = n-1;
    int s1, s2;
    int ans = 2e9;
    
    while(a < b){
        int cur = v[a]+v[b];
        if(ans > abs(cur)){
            ans = abs(cur);
            s1=v[a];
            s2=v[b];   
        }

        if(cur>0){
            b--;
        }
        else if(cur<0){
            a++;
        }
        else if(cur == 0){
            s1 = v[a];
            s2 = v[b];
            break;
        }
    }

    cout << s1 << " "<< s2;
}