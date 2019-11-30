#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "いくつ * を出力しますか？\n";
    cin >> num;

    for (int i=1; i<=num; i++){
        cout << '*';
    }
    cout << '\n';

    return 0;
}