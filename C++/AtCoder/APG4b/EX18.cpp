#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  
  //表を'-'で埋める
  vector<vector<char>> v(n, vector<char>(n));
  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
      v.at(i).at(j) = '-';
    }
  }

  //対戦結果を入力する
  for (int i=0; i<m; i++){
    int a,b;
    cin >> a >> b;
    v.at(a-1).at(b-1) = 'o';
    v.at(b-1).at(a-1) = 'x';
  }

  //表を出力する
  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
      cout << v.at(i).at(j);
      if (j == n-1){
        cout << endl;
        break;
      }
      cout << " ";
    }
  }
}
