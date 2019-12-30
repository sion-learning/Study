#include <bits/stdc++.h>
using namespace std;

int vectorCalc(int n){
  int sum = 0;
  vector<int> v(n);
  for (int i=0; i<n; i++){
    cin >> v.at(i);
    sum = sum + v.at(i);
  }
  return sum;
}
  

int main(){
  int n;
  cin >> n;
  
  int a,b,c;
  a = vectorCalc(n);
  b = vectorCalc(n);
  c = vectorCalc(n);
  
  cout << a*b*c << endl;
}  
