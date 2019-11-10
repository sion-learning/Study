#include <iostream>
using namespace std;

int main()
{
    int num1, num2;

    num1 = 3;
    cout << "変数num1の値は" << num1 << "です。\n";

    num2 = num1;
    cout << "変数num1の値をnum2に代入しました。\n";
    cout << "変数num2の値は" << num2 << "です。\n";

    // num1の値を変更しても、num2の値は変わらない。
    // なので、参照渡しをしているわけではない。
    num1 = 16;
    cout << "変数num1の値を変更しました。\n";
    cout << "変数num1の値は" << num1 << "です。\n";
    cout << "変数num2の値は" << num2 << "です。\n";

    return 0;
}