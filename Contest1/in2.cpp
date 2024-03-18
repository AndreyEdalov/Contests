#include <iostream>

using namespace std;
int main(){
    float n,q1 = 1, q2 = 1, summa = 0;
    cin >> n;
    while (q2-1 != n){
        summa += q1/q2;
        q1*=-1;
        q2+=1;
    }
    cout << summa << endl;
    return 0;
}