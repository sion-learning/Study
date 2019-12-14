#include <iostream>
using namespace std;

int main()
{
    const int num = 5;
    int test[num];

    cout << num << "人の点数を入力してください。\n";
    for(int i=0; i<num; i++){
        cin >> test[i];
    }

    for(int j=0; j<num; j++){
        cout << j+1 << "番目の人の点数は" << test[j] << "です。\n";
    }

    return 0;
}