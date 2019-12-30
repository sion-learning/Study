#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, s;
  cin >> n >> s;
  
  vector<int> av(n);
  for (int i=0; i<n; i++){
    cin >> av.at(i);
  }
  vector<int> pv(n);
  for (int j=0; j<n; j++){
    cin >> pv.at(j);
  }
  
  int cnt = 0;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(av[i] + pv[j] == s){
        cnt++;
      }
    }
  }
  
  cout << cnt << endl;
}
