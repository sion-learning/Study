#include <bits/stdc++.h>
using namespace std;

int count(vector<int> v, int n){
  int cnt = 0;
  bool chk = true;
  
  while(chk){
    for(int i=0; i<n; i++){
      if(v.at(i)%2 == 1){
        chk = false;
        break;
      }
    }
    for(int i=0; i<n; i++){
      v.at(i) = v.at(i)/2;
    }
    cnt++;
  }
  
  return cnt-1;
}

int main(){
  int n;
  cin >> n;
  vector<int> v(n);
  for(int i=0; i<n; i++){
    cin >> v.at(i);
  }
  
  int cnt = count(v, n);
  cout << cnt;
}

//https://qiita.com/drken/items/fd4e5e3630d0f5859067
//過去問精選10問！より