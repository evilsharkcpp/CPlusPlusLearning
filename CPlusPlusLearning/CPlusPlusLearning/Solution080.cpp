#include "Solution080.hpp"

void Solution080::dfs(int node, std::vector<std::vector<int>> &isConnected, std::vector<bool> &visit) {
    visit[node] = true;

    for (int i = 0; i < isConnected.size(); i++) {
        if (isConnected[node][i] && !visit[i]) {
            dfs(i, isConnected, visit);
        }
    }
}

int Solution080::findCircleNum(std::vector<std::vector<int>> &isConnected) {
    size_t n { isConnected.size() };
    int groupsCount {};

    std::vector<bool> visit(n);
    for (size_t i{}; i < n; ++i) {
        if (!visit[i]) {
            ++groupsCount;
            dfs(i, isConnected, visit);
        }
    }
    
    return groupsCount;
    
}