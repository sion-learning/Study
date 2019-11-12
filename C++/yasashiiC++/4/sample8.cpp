#include <iostream>
using namespace std;

int main()
{
    int inum = 160;
    double dnum;
    
    cout << "身長は" << inum << "センチです。\n";
    cout << "double型の変数に代入します。\n";

    dnum = inum;

    cout << "身長は" << dnum << "センチです。\n";

    return 0;
}