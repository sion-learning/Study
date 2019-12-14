#include <iostream>
using namespace std;

//func
void func();

int a = 0;

//main
int main()
{
    for(int i=0; i<5; i++)
        func();

    return 0;
}

//func
void func()
{
    int b = 0;
    static int c = 0;
    cout << "変数aは" << a << "　変数bは" << b << "　変数cは" << c << "です。\n";
    a++;
    b++;
    c++;
}