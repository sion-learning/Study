#include <iostream>
using namespace std;

//Carクラスの宣言
class Car{
    private:
        int num;
        double gas;
    public:
        int getNum(){return num;}
        double getGas(){return gas;}
        void show();
        void setNumGas(int n, double g);
};

//Carクラスメンバ関数の定義
void Car::show()
{
    cout << "車のナンバーは" << num << "です。\n";
    cout << "ガソリン量は" << gas << "です。\n";
}
void Car::setNumGas(int n, double g)
{
    if(g > 0 && g < 1000){
        num = n;
        gas = g;
        cout << "ナンバーを" << num << "にガソリン量を" << gas << "にしました。\n";
    }
    else{
        cout << g << "は正しいガソリン量ではありません。\n";
        cout << "ガソリン量を変更できませんでした。\n";
    }
}

//buy関数の宣言
void buy(Car& c);

int main()
{
    Car car1;

    car1.setNumGas(1234, 20.5);

    buy(car1);

    return 0;
}

//buy関数の定義 *引数としてポインタを使う
void buy(Car& c)
{
    int n = c.getNum();
    double g = c.getGas();
    cout << "ナンバー" << n << "、ガソリン量" << g << "の車を購入しました。\n";
}