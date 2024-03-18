#include <iostream>
#include <string>


bool ASCII_Check(const std::string& code){
    char simv;
    for (int x = 0; x <= code.length()-1; x++) {
        simv = code[x];
        if (not(((int) simv >= 33) and ((int) simv <= 127))){
            return false;
        }
    }
    return true;
}

bool length_check(const std::string& code){
    if ((8<=code.length()) & (code.length()<=14)){
        return true;
    }
    return false;
}

bool classe_check(const std::string& code){
    int upper = 0, lower = 0, numbers = 0, other = 0;
    char simv;
    for (int x = 0; x <= code.length()-1; x++) {
        simv = code[x];
        if (((int) simv <= 90) and ((int) simv >= 65)){
            if (upper == 0){
                upper++;
            }
        }
        else if ((((int) simv >=48) and ((int) simv <=57))){
            if (numbers == 0){
                numbers++;
            }
        }
        else if ((((int) simv >=97) and ((int) simv <=122))){
            if (lower == 0){
                lower++;
            }
        }
        else{
            if (other == 0){
                other++;
            }
        }
    }
    if ((upper+lower+numbers+other)>=3){
        return true;
    }
    return false;
}

int main(){
    std::string code;
    std::cin >> code;
    ASCII_Check(code);
    length_check(code);
    classe_check(code);
    if (ASCII_Check(code) & length_check(code) & classe_check(code)){
        std::cout << "YES" <<"\n";
    }
    else{
        std::cout << "NO" << "\n";
    }
    return 0;
}