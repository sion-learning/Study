#include <bits/stdc++.h>
using namespace std;

int main(){
  int h,w,count;
  cin >> h >> w;
  vector<string> v(h);
  for (int i=0; i<h; i++){
    cin >> v.at(i);
  }
  
  for (int i=0; i<h; i++){
    for (int j=0; j<w; j++){
      if (v.at(i).at(j) == '.'){
        count = 0;
        for (int k=-1; k<2; k++){
          for (int l=-1; l<2; l++){
            if(i+k >= 0 && i+k < h && j+l >= 0 && j+l < w)
              if (v.at(i+k).at(j+l) == '#') count++;
          }
        }
        v.at(i).at(j) = '0' + count;
      }
    }
  }

  for (int i=0; i<h; i++){
    cout << v.at(i) << endl;
  }
}
  