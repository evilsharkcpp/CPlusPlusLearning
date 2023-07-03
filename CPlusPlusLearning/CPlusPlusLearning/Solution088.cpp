#include "Solution088.hpp"

long long Solution088::minOperations(std::vector<int> &nums1,
 std::vector<int> &nums2, int k) {
    if(nums1 == nums2) {
        return 0;
    }

    if(k == 0) {
        return -1;
    }

    long long counter{};
    long long totalSum{};
    size_t n { nums1.size() };
    for(size_t i{}; i < n; ++i) {
        long long num{nums1[i] - nums2[i]};
        
        if(num % k == 0) {
            totalSum += num / k;
            if(num > 0) {
                counter += num / k;
            }
        } else {
            return -1;
        }
    }
    
    return totalSum == 0 ? counter : -1;
}
