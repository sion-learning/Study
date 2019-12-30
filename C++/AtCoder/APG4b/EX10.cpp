#include <bits/stdc++.h>
using namespace std;

void graph(int n){
  int i = 0;
  while(i < n){
    cout << "]";
    i++;
  }
  cout << endl;
}

int main(){
  int a,b;
  cin >> a >> b;
  
  cout << "A:";
  graph(a);
  
  cout << "B:";
  graph(b);
}
  
