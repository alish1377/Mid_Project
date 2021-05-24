#ifndef _DFS_H_
#define _DFS_H_

#include <iostream>
#include "algorithm"
#include <array>
#include <vector>
#include <thread>
#include <chrono>

class dfs
{
public:
    dfs(std::vector<std::vector<char>> , std::array<int,4>);
    void dfs_maze(std::vector<std::vector<char>>);
    void check_maze(int , int);
    void show();
    std::vector<std::vector<int>>temp_ans;
    std::vector<std::vector<int>>comp_ans;


private:
    std::vector<std::vector<char>>maze;
    int Rows;
    int Columns;
    int x_s;
    int x_e;
    int y_s;
    int y_e;
};

#endif 
