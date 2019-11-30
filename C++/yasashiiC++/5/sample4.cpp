#include <iostream>
using namespace std;

int main()
{
    int res;
    cout << "整数を入力してください。\n";
    cin >> res;
    if (res == 1) {
        cout << "1が入力されました。\n";
    } else if (res == 2) {
        cout << "2が入力されました。\n";
    } else {
        cout << "1か2を入力してください。\n";
    }

    return 0;
}