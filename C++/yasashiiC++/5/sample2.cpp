#include <iostream>
using namespace std;

int main()
{
    int res;
    cout << "整数を入力してください。\n";

    cin >> res;

    if (res == 1){
        cout << "1が入力されました。\n";
        cout << "1を選択しました。\n";
    }

    cout << "処理を終了します。\n";

    return 0;
}