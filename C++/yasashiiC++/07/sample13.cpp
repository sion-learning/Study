#include <iostream>
using namespace std;

//関数テンプレート
template <class T>
T maxT(T x, T y)
{
    if(x > y)
        return x;
    else
        return y;
}

int main()
{
    int a, b;
    double da, db;

    cout << "2つの整数を入力してください。\n";
    cin >> a >> b;

    cout << "2つの小数を入力してください。\n";
    cin >> da >> db;

    int ans1 = maxT(a, b);
    double ans2 = maxT(da, db);

    cout << "整数値の最大値は" << ans1 << "です。\n";
    cout << "小数値の最大値は" << ans2 << "です。\n";

    return 0;
}
