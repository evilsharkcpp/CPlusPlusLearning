#pragma once

#include<vector>

///<summary>
/// https://leetcode.com/number-of-provinces
///</summary>
class Solution080 {
private:
    void dfs(int node, std::vector<std::vector<int>>& isConnected, std::vector<bool>& visit); 
public:
    int findCircleNum(std::vector<std::vector<int>>& isConnected);
};