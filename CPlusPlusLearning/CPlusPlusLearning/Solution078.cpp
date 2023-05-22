#include "Solution078.hpp"

bool Solution078::isPowerOfTwo(int n) {
    return n <= 0 ? false : (n & (n - 1)) == 0; 
}