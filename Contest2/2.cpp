#include <iostream>
#include <string>

void check_polindrom(std::string& stroka_with_spaces){
    std::string stroka;
    for(char ch : stroka_with_spaces){
        if (ch != ' '){
            stroka+=ch;
        }
    }
    int first = 0;
    size_t length = stroka.length()-1;
    if (length == 0){
        std::cout << "yes" << "\n";
        return;
    }
    while (first < length) {
        if (stroka[first] != stroka[length]) {
            std::cout << "no" << "\n";
            return;

        }
        first++;
        length--;
    }
    std::cout << "yes" << "\n";
}

int main(){
    std::string stroka;
    std::getline(std::cin , stroka);
    check_polindrom(stroka);
    return 0;
}