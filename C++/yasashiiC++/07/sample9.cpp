#include <iostream>
using namespace std;

//inlineを使ったmax関数の定義
inline int max(int x, int y){if(x>y) return x; else return y;}

int main()
{
    int num1, num2, ans;
    cout << "１番目の整数を入力してください。\n";
    cin >> num1;

    cout << "２番目の整数を入力してください。\n";
    cin >> num2;

    ans = max(num1, num2);

    cout << "最大値は" << ans << "です。\n";

    return 0;
}