#include "DFS.h"

dfs::dfs(std::vector<std::vector<char>>_maze , std::array<size_t,4> _inputs , std::string _algorithm)
    :algorithm{_algorithm}
    , maze(_maze)
{
    std::cout<<"dfs constructor"<<std::endl;
    auto it = _inputs.begin();
    x_s = *(it);
    y_s = *(it+1);
    x_e = *(it+2);
    y_e =*(it+3);

}
std::vector<std::vector<size_t>> dfs::dfs_maze(std::vector<std::vector<char>> maze){
    //std::cout<<maze[3][4]<<std::endl;
    /*std::vector<std::vector<size_t>> ans(1,std::vector<size_t>(2 , '0')){x_s,y_s};

    bool arr_check[Rows][Columns];
    arr_check[x_s-1][y_s-1] = 1;*/
}

void dfs::check_maze(size_t x , size_t y){
    size_t x_temp{x};
    size_t y_temp{y};
    int coordinate[4][2] = {{0,-1},{-1,0},{0,1},{1,0}};
    for (size_t i = 0; i < 4; i++)
    {
        x_temp = x_temp + coordnate[i][0];
        y_temp = y_temp + coordnate[i][1];
        if(x_temp >= 0 && x_temp < Rows && y_temp <=0 && y_temp > Columns ){
            continue;
        }
        if()
    }
}