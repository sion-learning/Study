#include <bits/stdc++.h>
using namespace std;

int main(){
  int n = 5;
  vector<int> v(5);
  for (int i=0; i<n; i++){
    cin >> v.at(i);
  }
  
  string ans = "NO";
  for (int i=0; i<n-1; i++){
    if(v.at(i) == v.at(i+1)){
      ans = "YES";
      break;
    }
  }
  
  cout << ans << endl;
}
