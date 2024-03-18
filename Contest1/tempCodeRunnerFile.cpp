#include <iostream>

int main() {
    for (int x = 0; x <= 15; x++){
        std::cout << "\t" <<std::hex << std::uppercase << x; 
    } 
    std::cout << std::endl; 

    for (int i = 2; i <= 7; i++){
        std::cout << std::hex << std::uppercase << i << "\t";
        for (int j = 0; j < 16; ++j) {
            int ascii = 16 * i + j;
            if (ascii < 32 || ascii > 126) {
                std::cout << "\t";
            } 
            else if(j != 0) {
                std::cout << "\t" << char(ascii);
            }
            else{
                std::cout << char(ascii);
            }

        }
        std::cout << std::endl;
    }
    return 0;
}