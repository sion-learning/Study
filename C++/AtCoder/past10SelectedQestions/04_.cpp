#include <bits/stdc++.h>
using namespace std;

int main(){
  int c500 = 500;
  int c100 = 100;
  int c50 = 50;
  
  int a,b,c,t;
  cin >> a >> b >> c >> t;
  
  int count = 0;
  for (int i=0; i<=a; i++){
    for (int j=0; j<=b; j++){
      for (int k=0; k<=c; k++){
        if (c500*i + c100*j + c50*k == t)
          count++;
      }
    }
  }
  
  cout << count;
}

//https://qiita.com/drken/items/fd4e5e3630d0f5859067
//過去問精選10問！より

