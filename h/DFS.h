#ifndef _DFS_H_
#define _DFS_H_

#include <iostream>
#include "algorithm"
#include <array>
#include <vector>

class dfs
{
public:
    dfs() = default;
    dfs(std::vector<std::vector<char>> , std::array<size_t,4> ,std::string );
    std::string algorithm;
    std::vector<std::vector<size_t>>dfs_maze(std::vector<std::vector<char>>);
    void check_maze(size_t , size_t);
    std::vector<std::vector<size_t>>ans;

private:
    std::vector<std::vector<char>>maze;
    size_t x_s;
    size_t x_e;
    size_t y_s;
    size_t y_e;
};

#endif 
