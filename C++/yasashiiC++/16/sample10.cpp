#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    ofstream fout("test0.txt");
    if(!fout){
        cout << "ファイルをオープンできませんでした。\n";
        return 1;
    }
    else{
        cout << "ファイルをオープンしました。\n";
    }

    fout.close();
    cout << "ファイルをクローズしました。\n";

    return 0;
    
}