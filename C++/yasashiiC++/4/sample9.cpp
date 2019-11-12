#include <iostream>
using namespace std;

int main()
{
    double dnum = 160.5;
    int inum;
    
    cout << "身長は" << dnum << "センチです。\n";
    cout << "int型の変数に代入します。\n";

    //inum = dnum;
    inum = (int)dnum; //キャスト演算子で型を明示する

    cout << "身長は" << inum << "センチです。\n";

    return 0;
}