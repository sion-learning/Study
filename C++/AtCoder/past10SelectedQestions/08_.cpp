#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,y;
  cin >> n >> y;
  int a10000 = -1, a5000 = -1, a1000 = -1;

  for (int i=0; i<=n; i++){
    for (int j=0; i+j<=n; j++){
      int k = n - i - j;
      if (i*10000 + j*5000 + k*1000 == y){
        a10000 = i;
        a5000 = j;
        a1000 = k;
      }
    }
  }
  
  cout << a10000 << " " << a5000 << " " << a1000 << endl;
}

