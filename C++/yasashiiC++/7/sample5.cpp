#include <iostream>
using namespace std;

//buy関数の定義
void buy(int x, int y)
{
    cout << x << "万円と" << y << "万円の車を買いました。\n";
}

//buy関数の呼び出し
int main()
{
    int num1, num2;

    cout << "いくらの車を買いますか？\n";
    cin >> num1;

    cout << "いくらの車を買いますか？\n";
    cin >> num2;

    buy(num1, num2);

    return 0;
}