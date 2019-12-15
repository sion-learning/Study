#include <iostream>
using namespace std;

//buy関数の宣言
void buy(int x=10);

//buy関数の呼び出し
int main()
{
    cout << "１回目は100万円で購入します。\n";
    buy(100);

    cout << "２回目はデフォルト金額で購入します。\n";
    buy();

    return 0;
}

//buy関数の定義
void buy(int x)
{
    cout << x << "万円の車を買いました。\n";
}