#include <bits/stdc++.h>
using namespace std;

int calc(int x, string op, int y){
  if(op=="+"){
    return x+y;
  } else if(op=="-") {
    return x-y;
  } else if(op=="*") {
    return x*y;
  } else if(op=="/") {
    return x/y;
  }
}

int main(){
  int n,a;
  cin >> n >> a;
  
  for(int i=0; i<n; i++){
    string op;
    int b;
    cin >> op >> b;
    
    if (op=="/" && b==0){
      cout << "error" << endl;
      break;
    } else if (op=="+" || op=="-" || op=="*" || op=="/") {
      a = calc(a, op, b);
      cout << i+1 << ":" << a << endl;
    } else {
      cout << "error" << endl;
      break;
    }
  }
}
    
