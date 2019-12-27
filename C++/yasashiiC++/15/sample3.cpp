#include <iostream>
#include <string>
using namespace std;

//Carクラスの宣言
class Car{
    private:
        int num;
        double gas;
        char* pName;
    public:
        Car(char* pN, int n, double g);
        ~Car();
        Car(const Car& c);
        Car& operator=(const Car& c);
};

//Carクラスメンバ関数の定義
Car::Car(char* pN, int n, double g)
{
    pName = new char[strlen(pN)+1];
    strcpy(pName, pN);
    num = n;
    gas = g;
    cout << pName << "を作成しました。\n";
}
Car::~Car()
{
    cout << pName << "を破棄します。\n";
    delete[] pName;
}
Car::Car(const Car& c)
{
    cout << c.pName << "で初期化します。\n";
    pName = new char[strlen(c.pName) + strlen("のコピー1"+1)];
    strcpy(pName, c.pName);
    strcat(pName, "のコピー1");
    num = c.num;
    gas = c.gas;
}
Car& Car::operator=(const Car& c)
{
    cout << pName << "に" << c.pName << "を代入します。\n";
    if(this != &c){
        delete[] pName;
        pName = new char[strlen(c.pName)+strlen("のコピー2")+1];
        strcpy(pName, c.pName);
        strcat(pName, "のコピー2");
        num = c.num;
        gas = c.gas;
    }
    return *this;
}

//Carクラスの利用
int main()
{
    Car mycar("mycar", 1234, 25.5);
    Car car1 = mycar;
    Car car2("car2", 0, 0);
    car2 = mycar;

    return 0;
}