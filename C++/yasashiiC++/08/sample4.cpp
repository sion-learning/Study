#include <iostream>
using namespace std;

int main()
{
    int a = 5;
    int b = 10;
    int* pA;

    pA = &a;

    cout << "変数aの値は" << a << "です。\n";
    cout << "ポインタpAの値は" << pA << "です。\n";
    cout << "*pAの値は" << *pA << "です。\n";

    pA = &b;

    cout << "変数bの値は" << b << "です。\n";
    cout << "ポインタpAの値は" << pA << "に変更されました。\n";
    cout << "*pAの値は" << *pA << "です。\n";

    return 0;
}