#include "Solution092.hpp"

bool Solution092::isUgly(int n) {
    if(n == 0) {
        return false;
    }

    if(n == 1) {
        return true;
    } 

    for(const auto& num : {2, 3, 5}) {
        if(n % num == 0) {
            return isUgly(n / num);
        }
    }
    
    return false;
}