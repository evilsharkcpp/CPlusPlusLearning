#include "Solution072.hpp"

double Solution072::average(std::vector<int> &salaries) {
        
    int min { *min_element(salaries.begin(), salaries.end()) };
    int max { *max_element(salaries.begin(), salaries.end()) };
    
    int sum{};
    for(const auto& salary : salaries) {
        sum += salary;
    }
    
    return static_cast<double>(sum - (max + min)) /
    static_cast<double>(static_cast<int>(salaries.size()) - 2);
}