#include "Solution067.hpp"

bool Solution067::isPerfectSquare(int num){
    long start{}, end{ num }, middle{};

    while(start <= end) {
        middle = (end + start) / 2;
        long quad{ middle * middle };
            
        if(quad == num) {
            return true;
        }
        else if (quad < num) {
            start = middle + 1;
        }
        else {
            end = middle - 1;
        }
    }

    return false;
}