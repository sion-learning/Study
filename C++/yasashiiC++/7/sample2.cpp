#include <iostream>
using namespace std;

//buy関数の定義
void buy()
{
    cout << "車を買いました。\n";
}

//buy関数の利用
int main()
{
    buy();

    cout << "もう１台車を購入します。\n";

    buy();

    return 0;
}