#include <iostream>
using namespace std;

int main()
{
    int i;
    double d;
    char str[100];

    cout << "整数値を入力してください。\n";
    cin >> i;
    cout << "小数値を入力してください。\n";
    cin >> d;
    cout << "文字列を入力してください。\n";
    cin >> str;

    cout << "入力した整数値は" << i << "です。\n";
    cout << "入力した小数値は" << d << "です。\n";
    cout << "入力した文字列は" << str << "です。\n";

    return 0;
}