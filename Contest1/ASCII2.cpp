#include <string>
#include <iostream>

using namespace std;

int main()
{
    int xcoll[17] = {50, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int ycoll[7] = {50, 2, 3, 4, 5, 6, 7};

    for (int y: ycoll) {
        for (int x: xcoll) {
            if (x == 50 && y == 50) {
                cout << "\t";
            } else if (y == 50) {
                if (x == 10) {
                    cout << 'A' << "\t";
                } else if (x == 11) {
                    cout << 'B' << "\t";
                } else if (x == 12) {
                    cout << 'C' << "\t";
                } else if (x == 13) {
                    cout << 'D' << "\t";
                } else if (x == 14) {
                    cout << 'E' << "\t";
                } else if (x == 15) {
                    cout << 'F' << "\t";
                } else {
                    cout << x << "\t";
                }
            } else if (x == 50) {
                cout << y << "\t";
            } else if (x == 15) {
                cout << char(y*16 + x);
            } else {
                cout << char(y*16 + x) << "\t";
            }
        }
        cout << endl;
    }
};