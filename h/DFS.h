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
    dfs(std::array<size_t,6> ,std::string );
    std::string algorithm;
    std::vector<std::vector<char>> make_maze();
    std::vector<std::vector<size_t>>dfs_maze(std::vector<std::vector<char>>);
    void check_maze(size_t , size_t);
    std::vector<std::vector<size_t>>ans;

private:
    size_t Rows;
    size_t Columns;
    size_t x_s;
    size_t x_e;
    size_t y_s;
    size_t y_e;
};

#endif 
