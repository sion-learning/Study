#include <iostream>
using namespace std;

int main()
{
    int res;
    cout << "整数を入力してください。\n";
    cin >> res;

    if (res == 1){
        cout << "1が入力されました。\n";
    } else {
        cout << "1以外が入力されました。\n";
    }

    return 0;
}