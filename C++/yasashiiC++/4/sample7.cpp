#include <iostream>
using namespace std;

int main()
{
    int a = 1;
    int b = 0;

    cout << "short int型のサイズは" << sizeof(short int) << "バイトです。\n";
    cout << "int型のサイズは" << sizeof(int) << "バイトです。\n";
    cout << "long int型のサイズは" << sizeof(long int) << "バイトです。\n";
    cout << "float型のサイズは" << sizeof(float) << "バイトです。\n";
    cout << "double型のサイズは" << sizeof(double) << "バイトです。\n";
    cout << "long型のサイズは" << sizeof(long) << "バイトです。\n";
    cout << "変数aのサイズは" << sizeof(a) << "バイトです。\n";
    cout << "式a+bのサイズは" << sizeof(a+b) << "バイトです。\n";

    return 0;
}