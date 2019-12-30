#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

int main(){
  int n;
  cin >> n;
  
  vector<int> a(n);
  for (int i=0; i<n; i++){
    cin >> a.at(i);
  }
  
  int sum = 0;
  for (int i=0; i<n; i++){
    sum += a.at(i);
  }
  int mean = sum / n;
  
  for (int i=0; i<n; i++){
    cout << abs(a.at(i) - mean) << endl;
  }
}
