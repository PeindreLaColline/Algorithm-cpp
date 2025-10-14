//20:51
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int num;
vector<int> card;

int binary(int num){
    int s = 0;
    int e = n-1;

    while(s <= e){
        int mid = (s+e)/2;

        if(card[mid] < num) s = mid +1;
        else if(card[mid] > num) e = mid -1;
        else return mid;
    }

    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    card.resize(n);
    for(int i =0; i<n; i++){
        cin >> card[i];
    }
    sort(card.begin(), card.end());

    cin >> m;
    int cnt;
    for(int i =0; i<m; i++){
        cin >> num;
        int idx = binary(num);
        if(idx != -1){
            cnt = upper_bound(card.begin(), card.end(), card[idx]) - lower_bound(card.begin(), card.end(), card[idx]);
            cout << cnt << " ";
        }
        else{
            cout << 0 << " ";
        }
        
    }

}