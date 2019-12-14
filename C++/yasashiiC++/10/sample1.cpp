#include <iostream>
using namespace std;

//func関数の宣言
void func();

int a = 0;

//main関数
int main()
{
    int b = 1;

    cout << "main関数では変数aとbが使えます。\n";
    cout << "変数aの値は" << a << "です。\n";
    cout << "変数bの値は" << b << "です。\n";
    //cout << "変数cの値は" << c << "です。\n";

    func();

    return 0;
}

//func関数の定義
void func()
{
    int c = 2;

    cout << "func関数では変数aとcが使えます。\n";
    cout << "変数aの値は" << a << "です。\n";
    //cout << "変数bの値は" << b << "です。\n";
    cout << "変数cの値は" << c << "です。\n";
}