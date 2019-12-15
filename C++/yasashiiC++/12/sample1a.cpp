#include <iostream>
using namespace std;

//Carクラスの宣言
class Car{
    public:
        int num;
        double gas;
        void show();
};

//Carクラスメンバの定義
void Car::show()
{
    cout << "車のナンバーは" << num << "です。\n";
    cout << "ガソリン量は" << gas << "です。\n";
}

int main()
{
    Car* pCar;

    pCar = new Car;

    pCar->num = 1234;
    pCar->gas = 20.5;

    pCar->show();

    delete pCar;

    return 0;
}