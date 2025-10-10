//17:02
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> card;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    card.resize(n);
    for(int i =0; i<n; i++){
        cin >> card[i];
    }
    sort(card.begin(), card.end(), less<>());

    cin >> m;
    int check;
    for(int i =0; i<m; i++){
        cin >> check;

        int s = 0;
        int e = n-1;
        bool done = false;
        while(s<=e){
            int mid = (s+e)/2;

            if(card[mid] == check){
                done = true;
                break;
            }
            else if(card[mid] < check){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        if(done) cout << 1 << " ";
        else cout << 0 << " ";
    }

}