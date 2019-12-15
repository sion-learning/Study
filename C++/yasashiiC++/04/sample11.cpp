#include <iostream>
using namespace std;

int main()
{
    int num1 = 5;
    int num2 = 4;
    double div;

    // div = num1/num2;
    div = (double)num1/num2; // 大きい方の型に小さい方の型を変換した上で演算する

    cout << "5/4は" << div << "です。\n";

    return 0;
}