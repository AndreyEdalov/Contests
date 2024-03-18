#include <iostream>

using namespace std;

int main(){
    int v, t, distance_mkad, length = 109;
    cin >> v;
    cin >> t;
    if (v > 0){
        distance_mkad = (v*t)%109;
        if (distance_mkad == 109){
            distance_mkad = 0;
        }
        cout << distance_mkad << endl;
    }
    else if(v < 0){
        distance_mkad = 109 -((-v*t)%109);
        if (distance_mkad == 109){
            distance_mkad = 0;
        }
        cout << distance_mkad << endl;
    }
    else{
        cout << 0 << endl;
    }
    return 0;


}