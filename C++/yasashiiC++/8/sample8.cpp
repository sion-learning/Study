#include <iostream>
using namespace std;

int main()
{
    int a = 5;
    int& rA = a;

    cout << "変数aの値は" << a << "です。\n";
    cout << "参照rAの値は" << rA << "です。\n";
    cout << "変数aのアドレスは" << &a << "です。\n";
    cout << "参照rAのアドレスも" << &rA << "です。\n";

    rA = 50;

    cout << "rAに50を代入しました。\n";
    cout << "参照rAの値は" << rA << "に変更されました。\n";
    cout << "変数aの値も" << a << "に変更されました。\n";
    cout << "変数aのアドレスは" << &a << "です。\n";
    cout << "参照rAのアドレスも" << &rA << "です。\n";

    return 0;
}
