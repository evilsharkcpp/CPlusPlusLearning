#include "Solution097.hpp"

int Solution097::hammingWeight(uint32_t n) {
    int ret{};
    while(n > 0) { 
        n = n & (n - 1);
        ++ret; 
    }

    return ret;
}