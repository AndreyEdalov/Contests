#include <iostream>
using namespace std;

int main(){
    int K, remainder;
    cin >> K;
    string N;
    cin >> N;
    for (char digit: N){
        remainder = (remainder * 10 + (digit - '0')) % K;
    }
    cout << remainder;
    return  0;
}