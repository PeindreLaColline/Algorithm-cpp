/*16:28*/
/*
v[a][b] = v[a-1][1] ~ v[a-1][b]의 합
*/
#include <iostream>
#include <vector>
using namespace std;

int test_case;
int k, n;
vector<int> num;

int main(){
    cin>>test_case;
    for(int t = 0; t<test_case; t++){
        cin >>k >> n;
        num.clear();
        num.resize(n+1);
        for(int i = 0; i<=n; i++){
            num[i] = i;
        }

        for(int i =1; i<=k; i++){
            for(int j = 1; j<=n; j++){
                num[j] += num[j-1];
            }
        }

        cout << num[n]<<endl;
        
    }
}