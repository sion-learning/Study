#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  
  int c = 0;
  for(int i=0; i<s.size(); i++){
    if(s.at(i) == '1'){
      c++;
    }
  }
  
  cout << c;
}

//https://qiita.com/drken/items/fd4e5e3630d0f5859067
//過去問精選10問！より