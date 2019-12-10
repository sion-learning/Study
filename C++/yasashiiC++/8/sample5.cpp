#include <iostream>
using namespace std;

int main()
{
    int a = 5;
    int *pA = &a;

    cout << "変数aの値は" << a << "です。\n";

    *pA = 50;

    cout << "*pAに50を代入しました。\n";
    cout << "変数aの値は" << a << "です。\n";

    return 0;
}