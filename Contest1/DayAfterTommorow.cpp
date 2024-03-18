#include <iostream>




int main(){
    int year, month, day;
    bool leap_year;
    std::cin >> day >> month >> year;
    
    if ((year % 100 != 0 && year % 4 == 0) || (year % 400 == 0)){
        leap_year = true;
    }
    else{
        leap_year = false;
    }
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
        if (1<=day && day <= 29){
            std::cout << day+2 <<" "<<month<<" "<<year <<"\t";
        }
        else if(day == 30){
            if (month == 12){
                std::cout << 1 <<" "<<1<<" "<<year+1 <<"\t";
            }
            else {
                std::cout << 1 <<" "<<month+1<<" "<<year <<"\t";
            }
        }

        else if(day == 31){
            if (month == 12){
                std::cout << 2 <<" "<<1<<" "<<year+1 <<"\t";
            }
            else{
                std::cout << 2 <<" "<<month+1<<" "<<year <<"\t";
            }
        }

    }

    else if (month == 4 || month == 6 || month == 9 || month == 11){
        if (1<=day && day <= 28){
            std::cout << day+2 <<" "<<month<<" "<<year <<"\t";
        }
        else if(day == 29){
            std::cout << 1 <<" "<<month+1<<" "<<year <<"\t";
        }
        else if(day == 30){
            std::cout << 2 <<" "<<month+1<<" "<<year <<"\t";
    }
    }
    else if (month == 2){
        if (1<=day && day <= 26){
            std::cout << day+2 <<" "<<month<<" "<<year <<"\t";
        }

        else if (day == 27){
            if (leap_year == true){
                std::cout << day+2 <<" "<<month<<" "<<year <<"\t";
            }
            else{
                std::cout << 1 <<" "<<month+1<<" "<<year <<"\t";
            }
        }
        else if (day == 28){
            if (leap_year == true){
                std::cout << 1 <<" "<<month+1<<" "<<year <<"\t";
            }
            else{
                std::cout << 2 <<" "<<month+1<<" "<<year <<"\t";
            }
        }
        else if (day == 29){
            std::cout << 2 <<" "<<month+1<<" "<<year <<"\t";
        }
    }
    return 0;
}