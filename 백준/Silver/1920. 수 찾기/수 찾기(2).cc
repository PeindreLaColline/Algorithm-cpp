/*23:12*/
/* 이진 탐색 사용 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i =0; i<n; i++){
        cin >> v[i];
    }

    int nn;
    cin >> nn;

    vector<int> vv(nn);
    for(int i =0; i<nn; i++){
        cin >>vv[i];
    }

    sort(v.begin(), v.end());

    for(int i =0; i<nn; i++){
        int s = 0;
        int e = v.size()-1;
        bool done = false;
        while(s<=e){
            int mid = (s+e)/2;
    
            if(v[mid] == vv[i]){
                done = true;
                cout << 1 << "\n";
                break;
            }
            else if(v[mid] < vv[i]){
                s = mid+1;
            }
            else{
                e = mid -1;
            }
        }
        if(!done) cout << 0 << "\n";
    }

}
