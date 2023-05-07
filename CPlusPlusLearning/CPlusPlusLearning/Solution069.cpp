#include "Solution069.hpp"

double Solution069::myPow(double x, int n){
    if(x == 1.0) {
        return 1.0;
    }
    if(x == -1.0) {
        return n % 2 == 0 ? 1.0 : -1.0;
    }

    if(n == 0) {
        return 1.0;
    }
    if(n == std::numeric_limits<int>::max()) {
        return abs(x) > 1 ? std::numeric_limits<double>::max() : std::numeric_limits<double>::min();
    }
    if(n == std::numeric_limits<int>::min()) {
        return abs(x) < 1 ? std::numeric_limits<double>::max() : std::numeric_limits<double>::min();
    }

    
    if(n < 0) {
        n = -n;
        x = 1.0 / x;
    }
    double result{ x };
    for(int i{}; i < n - 1; ++i) {
        result *= x;
    }
    return result;
}