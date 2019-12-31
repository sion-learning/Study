#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,a,b;
  cin >> n >> a >> b;
  
  int num = 0;
  int sum = 0;
  int dig = 0;
  int ans = 0;
  for (int i=1; i<=n; i++){
    num = i;
    sum = 0;
    while (num) {
      dig = num % 10;
      sum = sum + dig;
      num = num / 10;
    }
    if (a <= sum && sum <=b){
      ans = ans + i;
    }
  }
  cout << ans << endl;
}

//https://qiita.com/drken/items/fd4e5e3630d0f5859067
//過去問精選10問！より