#include <iostream>
#include <string>

using namespace std;

int main(){
    int N, K, x = 0;
    cin >> N >> K;

    cout << "\t";
    for (int x = 1; x<=N; x++){
        cout << x << "\t";
    }
    cout << endl;

    for (int i = 1; i <=N; i++){
        cout << i << "\t";
        for (int j = 1; j <= N; j ++){
                cout << i*j%K<< "\t";
            } 
            cout<<endl;
        }

    return 0;
    }



    