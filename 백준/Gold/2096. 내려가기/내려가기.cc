/*18:28*/
#include <iostream>
#include <vector>
using namespace std;

int n;

vector<vector<int> > mini;
vector<vector<int> > maxi;

int main(){
    cin >> n;

    mini.resize(2, vector<int>(3));
    maxi.resize(2, vector<int>(3));

    int a, b, c;

    cin >> a >> b >> c;

    mini[0][0] = a;
    mini[0][1] = b;
    mini[0][2] = c;

    maxi[0][0] = a;
    maxi[0][1] = b;
    maxi[0][2] = c;

    for(int i =1; i<n; i++){
        cin >> a >> b >> c;

        mini[1][0] = min(mini[0][0], mini[0][1]) + a;
        mini[1][1] = min(mini[0][0], min(mini[0][1], mini[0][2])) + b;
        mini[1][2] = min(mini[0][1], mini[0][2]) + c;

        maxi[1][0] = max(maxi[0][0], maxi[0][1]) + a;
        maxi[1][1] = max(maxi[0][0], max(maxi[0][1], maxi[0][2])) + b;
        maxi[1][2] = max(maxi[0][1], maxi[0][2]) + c;

        mini[0] = mini[1];
        maxi[0] = maxi[1];
    }

    cout << max(maxi[0][0], max(maxi[0][1], maxi[0][2])) << " " << min(mini[0][0], min(mini[0][1], mini[0][2]));

    


}