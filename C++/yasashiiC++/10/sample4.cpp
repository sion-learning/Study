#include <iostream>
using namespace std;

int main()
{
    int num;
    int* pT;
    //cout << "pTの値を表示します。 >> " << pT << "\n";

    cout << "何人のテストの点数を入力しますか？\n";

    cin >> num;
    pT = new int[num]; //ここで動的メモリ確保したのでポインタの値が変わる

    //int* pT = new int[num];
    //cout << "pTの値を表示します。 >> " << pT << "\n";

    cout << "人数分の点数を入力してください。\n";

    for(int i=0; i<num; i++){
        cin >> pT[i];
    }

    for(int j=0; j<num; j++){
        cout << j+1 << "番目の人の点数は" << pT[j] << "です。\n";
    }

    delete[] pT;

    return 0;
}