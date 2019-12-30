#include <bits/stdc++.h>
using namespace std;

int main(){
  string op;
  int a, b;
  
  cin >> a >> op >> b;
  if(op=="+")
    cout << a+b << endl;
  else if(op=="-")
    cout << a-b << endl;
  else if(op=="*")
    cout << a*b << endl;
  else if(op=="/"){
    if(b==0){
      cout << "error" << endl;
    } else {
      cout << a/b << endl;
    }
  }
  else
    cout << "error" << endl;
}
