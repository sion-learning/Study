#include <bits/stdc++.h>
using namespace std;

int check(vector<vector<int>> &v, int &correct, int &wrong){

  //九九とあっているかチェックして間違っていたら直す
  for (int i=0; i<9; i++){
    for (int j=0; j<9; j++){
      if(v.at(i).at(j) != (i+1) * (j+1)){
        v.at(i).at(j) = (i+1) * (j+1);
        wrong++;
      } else {
        correct++;
      }
    }
  }
}

int main(){
  
  //入力データをvectorに入れる
  vector<vector<int>> v(9, vector<int>(9));
  for (int i=0; i<9; i++){
    for (int j=0; j<9; j++){
      cin >> v.at(i).at(j);
    }
  }
  
  int wrong = 0; 
  int correct = 0;
  check(v, correct, wrong);  
  
  // vectorデータを出力する
  for (int i=0; i<9; i++){
    for (int j=0; j<9; j++){
      cout << v.at(i).at(j);
      if (j == 8){
        cout << endl;
        break;
      }
      cout << " ";
    }
  }
  cout << correct << endl;
  cout << wrong << endl;

}
