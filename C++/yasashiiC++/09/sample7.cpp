#include <iostream>
using namespace std;

//avg関数の宣言
double avg(int t[]);

int main()
{
    int test[5];

    cout << "5人のテストの点数を入力してください。\n";
    for(int i=0; i<5; i++){
        cin >> test[i];
    }
    double ans = avg(test);
    cout << "5人の平均点は" << ans << "点です。\n";

    return 0;
}

//avg関数の定義
double avg(int t[]){
    double sum = 0;
    for(int i=0; i<5; i++){
        sum += t[i];
    }
    return sum/5;
}
