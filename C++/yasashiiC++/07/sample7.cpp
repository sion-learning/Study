#include <iostream>
using namespace std;

//sum関数の定義
int sum(int x, int y)
{
    return x + y;
}

int main()
{
    int num1, num2, ans;

    cout << "1番目の整数を入力してください。\n";
    cin >> num1;

    cout << "2番目の整数を入力してください。\n";
    cin >> num2;

    ans = sum(num1, num2);
    cout << "合計は" << ans << "です。\n";

    return 0;

}