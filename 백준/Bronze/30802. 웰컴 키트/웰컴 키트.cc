#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
vector<int> shirt;
int tn, pn;

int main(){
    cin >> n;
    shirt.resize(6);
    for(int i=0; i<6; i++){
        cin>>shirt[i];
    }
    cin>> tn >>pn;


    int ans1 = 0;
    for(int i =0; i<6; i++){
        ans1+= ceil(double(shirt[i])/tn);
    }

    int ans2 = n/pn;
    int ans3 = n%pn;

    cout<<ans1<<endl;
    cout<<ans2<<" "<<ans3;

    
}