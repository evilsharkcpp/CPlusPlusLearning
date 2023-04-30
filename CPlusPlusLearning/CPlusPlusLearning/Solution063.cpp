#include "Solution063.hpp"

int Solution063::islandPerimeter(std::vector<std::vector<int>> &grid) {
    int innerEdges{};
    int totalBlocks{};
    
    for(size_t i{}; i < grid.size(); ++i) {
        for(size_t j{} ; j < grid[i].size(); ++j) {
            if(grid[i][j] == 1) {
                totalBlocks++;
                if(i + 1 < grid.size() && grid[i + 1][j] == 1) {
                    innerEdges++;
                }
                if(static_cast<int>(i) - 1 >= 0 && grid[i - 1][j] == 1) {
                    innerEdges++;
                }
                if(j + 1 < grid[i].size() && grid[i][j + 1] == 1) {
                    innerEdges++;
                }
                if(static_cast<int>(j) - 1 >= 0 && grid[i][j - 1] == 1) {
                    innerEdges++;
                }
            }
        }
    }

    return 4 * totalBlocks - innerEdges;
}