#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, d;
  cin >> n;
  set<int> st;
  for (int i=0; i<n; i++){
    cin >> d;
    st.insert(d);
  }
  
  cout << st.size();
}
    
//https://qiita.com/drken/items/fd4e5e3630d0f5859067
//過去問精選10問！より