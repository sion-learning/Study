#include <iostream>
using namespace std;

int main()
{
    int test[5] = {80,60,55,22,75};

    cout << "test[0]の値は" << test[0] << "です。\n";
    cout << "test[0]のアドレスは" << &test[0] << "です。\n";
    cout << "testの値は" << test << "です。\n";
    cout << "つまり*testの値は" << *test << "です。\n";

    return 0;
}