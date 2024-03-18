#include <iostream>
#include <string>

using namespace std;

void Sounds(const string& input, char scode[]) {
    scode[0] = input[0];

    int matchCount = 1;
    int codeCount = 1;
    while ((matchCount < input.length()) && (codeCount < 4)) {
        if (((input[matchCount] == 'b') || (input[matchCount] == 'p') || (input[matchCount] == 'v') || (input[matchCount] == 'f')) && (scode[codeCount - 1] != '1')) {
            scode[codeCount] = '1';
            codeCount++;
        } else if (((input[matchCount] == 'c') || (input[matchCount] == 'g') || (input[matchCount] == 'j') || (input[matchCount] == 'k') || (input[matchCount] == 'q') || (input[matchCount] == 's') || (input[matchCount] == 'x') || (input[matchCount] == 'z')) && (scode[codeCount - 1] != '2')) {
            scode[codeCount] = '2';
            codeCount++;
        } else if (((input[matchCount] == 'd') || (input[matchCount] == 't')) && (scode[codeCount - 1] != '3')) {
            scode[codeCount] = '3';
            codeCount++;
        } else if ((input[matchCount] == 'l') && (scode[codeCount - 1] != '4')) {
            scode[codeCount] = '4';
            codeCount++;
        } else if (((input[matchCount] == 'm') || (input[matchCount] == 'n')) && (scode[codeCount - 1] != '5')) {
            scode[codeCount] = '5';
            codeCount++;
        } else if ((input[matchCount] == 'r') && (scode[codeCount - 1] != '6')) {
            scode[codeCount] = '6';
            codeCount++;
        }
        matchCount++;
    }

    while (codeCount < 4) {
        scode[codeCount] = '0';
        codeCount++;
    }
    scode[4] = '\0';

    cout << scode << endl;
}

int main() {
    string str;
    cin >> str;
    char str2[5];
    Sounds(str, str2);
    return 0;
}
