#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;
vector<string> v;

bool compare(const string &a, const string &b){
    if (a.length() == b.length()) return a<b;
    else return a.length() < b.length();
}

int main(){
    cin>>n;
    v.resize(n);

    for(int i =0; i<n; i++){
        cin>>v[i];
    }

    sort(v.begin(), v.end(), compare);
    v.erase(unique(v.begin(), v.end()), v.end());

    for(int i =0; i<v.size(); i++){
        cout<<v[i]<<endl;
    }
}
