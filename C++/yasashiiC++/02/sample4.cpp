#include <iostream>
using namespace std;

int main()
{
    // macの場合は"Option+¥"で"\"を入力する。
    // ¥のまま入力するとそのまま出力される。ただし¥はリテラルで括るとエラーになる。””で括る。
    cout << "円記号を表示します。：" << "¥" << '\n';
    cout << "アポストロフィを表示します。：" << '\'' << '\n';

    // winの場合はエスケープが必要
    // cout << "円記号を表示します。：" << '¥¥' << '¥n';
    // cout << "アポストロフィを表示します。：" << '¥'' << '¥n';

}