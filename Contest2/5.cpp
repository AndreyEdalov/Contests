#include<iostream>
#include<string>


using namespace std;

int main() {
    string number;
    getline(cin, number);
    int length = number.size();
    if (number.back() < '9') {
        ++number.back();
    } else {
        int i = length - 1;
        while (number[i] == '9') {
            number[i] = '0';
            --i;
        }
        if (i < 0) {
            number = '1' + number;
        } else {
            ++number[i];
        }
    }
    cout << number << '\n';
}