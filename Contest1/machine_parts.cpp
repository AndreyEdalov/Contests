#include <iostream>
using namespace std;

int main() {
    int N, K, M, F, Sum = 0;
    cin >> M >> N >> K;


    while (N >= K && M >= N) {
        F = (M/N) * (N/K);
        M = M - F*K;
        Sum = Sum + F;
    }

    cout << Sum << endl;
    return 0;
}
