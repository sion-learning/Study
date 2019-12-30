#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int a = 1;
  
  for(int i=0; i<s.size()-1; i++){
    i++;
    if(s.at(i)=='+'){
      a++;
    } else {
      a--;
    }
  }
  
  cout << a << endl;
}
      
