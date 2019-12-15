#include <iostream>
using namespace std;

//構造体型Carの宣言
struct Car{
    int num;
    double gas;
};

//show関数の宣言
void show(Car c);

int main()
{
    Car car1 = {0, 0.0};

    cout << "ナンバーを入力してください。\n";
    cin >> car1.num;

    cout << "ガソリン量を入力してください。\n";
    cin >> car1.gas;

    show(car1);

    return 0;
}

//show関数の定義
void show(Car c)
{
    cout << "車のナンバーは" << c.num << "、ガソリン量は" << c.gas << "です。\n";
}