#include "Solution087.hpp"

std::vector<int> Solution087::sumZero(int n) {
    std::vector<int> result(n, 0);
    for(int i{}; i < n / 2; ++i) {
        result[i] = i + 1;
        result[n - i - 1] = -(i + 1);
    }
    
    return result;
}