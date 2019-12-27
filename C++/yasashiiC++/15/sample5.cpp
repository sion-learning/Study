#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int num;
    vector<int> vt;

    cout << "いくつ整数データを入力しますか？\n";
    cin >> num;

    for(int i=0; i<num; i++){
        int data;
        cout << "整数を入力して下さい。\n";
        cin >> data;
        vt.push_back(data);
    }

    cout << "表示します。\n";
    vector<int>::iterator it = vt.begin();
    while(it != vt.end()){
        cout << *it;
        cout << "-";
        it++;
    }
    cout << "\n";
}