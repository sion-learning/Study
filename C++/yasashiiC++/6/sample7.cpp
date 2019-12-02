#include <iostream>
using namespace std;

int main()
{
    int i = 1;
    do {
        cout << i << "番目の繰り返しです。\n";
        i++;
    } while (i <= 5);

    cout << "繰り返しが終わりました。\n";

    return 0;
}