#include <iostream>
#include "myfunc.h"
using namespace std;

int main()
{
    int num1, num2, ans;

    cout << "1番目の整数を入力してください。\n";
    cin >> num1;

    cout << "2番目の整数を入力してください。\n";
    cin >> num2;

    ans = max(num1, num2);

    cout << "最大値は" << ans << "です。\n";

    return 0;
}

//sample5をコンパイルするとき
//クラスを定義したhファイル(仮にclass.h)、
//メンバ関数を定義したcppファイル（仮にclass.cpp）、
//そのクラスを使用したmain.cppの複数ファイルがある場合
//
//c++ sample5.cpp myfunc.cpp
//./a.out