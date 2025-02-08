#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int test;
    int n;
    vector<int> v;
    vector<int> c;

    cin>>test;

    for(int t = 0; t < test; t++){
        v.clear();
        c.clear();
        cin>>n;
        v.resize(n);
        c.resize(n);
        for(int i =0; i<n; i++){
            cin>>v[i];
        }

        sort(v.begin(), v.end());

        int i = 1;
        int idx = n-2;
        c[(n-1)/2] = v[n-1];
        while(true){
            if(idx >= 0){
                c[(n-1)/2+i] = v[idx];
            }
            else break;
            idx--;
            if(idx >= 0){
                c[(n-1)/2-i] = v[idx];
            }
            else break;
            idx--;
            i++;
        }
        
        int M = 0;
        for(int i =0; i<n-1; i++){
            M = max(M, abs(c[i]-c[i+1]));
        }

        cout<<abs(M)<<endl;        
    }
}