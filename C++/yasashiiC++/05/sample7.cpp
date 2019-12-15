#include <iostream>
using namespace std;

int main()
{
    int res;
    char ans;
    cout << "何番目のコースにしますか？\n";
    cout << "整数を入力してください。\n";

    cin >> res;
    ans = (res == 1) ? 'A' : 'B';

    cout << ans << "コースを選択しました。\n";

    return 0;
}