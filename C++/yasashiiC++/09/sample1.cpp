#include <iostream>
using namespace std;

int main()
{
    int test[] = {80,60,22,50,75};

    //int test[5] = {80,60,22,50,75};

    //int test[5];
    //test[0] = 80;
    //test[1] = 60;
    //test[2] = 22;
    //test[3] = 50;
    //test[4] = 75;

    for(int i=0; i<5; i++){
        cout << i+1 << "番目の人の点数は" << test[i] << "です。\n";
    }

    return 0;
}