#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> num;
int ans;

bool comparator(const int &a, const int &b){
    return a>b;
}

void rope(int s, int mini, int cnt){
    for(int i =s+1; i<n; i++){
        
    }
}

int main(){
    cin>>n;
    num.resize(n);
    for(int i =0; i<n; i++){
        cin>>num[i];
    }
    sort(num.begin(), num.end(), comparator);

    ans = num[0];

    for(int i =1; i<n; i++){
        if(ans <= num[i]*(i+1)){
            ans = num[i]*(i+1);
        }
    }

    cout<<ans;
}