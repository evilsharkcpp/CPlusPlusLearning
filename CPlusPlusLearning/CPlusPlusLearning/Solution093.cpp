#include "Solution093.hpp"
#include <vector>

bool Solution093::isIsomorphic(std::string s, std::string t) {
    std::vector<char> st(256), ts(256);
    
    for (int i{}; i < s.size(); ++i) {
        if (st[s[i]] && t[i] != st[s[i]] ||
        ts[t[i]] && s[i] != ts[t[i]]) {
            return false;
        }   
        st[s[i]] = t[i];
        ts[t[i]] = s[i];
    }

    return true;
}