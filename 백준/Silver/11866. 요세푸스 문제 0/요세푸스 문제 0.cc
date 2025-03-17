#include <iostream>
#include <queue>
using namespace std;


int n, k;
queue<int> q;

int main(){
  cin >> n >> k;
  for(int i=1; i<=n; i++){
    q.push(i);
  }
  
  cout<<"<";
  int i=1;
  while(!q.empty()){
    if(i==k){
      i=1;
      cout<<q.front();
      q.pop();
      if(!q.empty()) cout<<", ";
      continue;
    }
    
    q.push(q.front());
    q.pop();
    i++;
    
  }
  cout<<">";  
  
}