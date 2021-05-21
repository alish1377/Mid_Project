#include "DFS.h"

dfs::dfs(std::array<size_t,6> _inputs , std::string _algorithm)
    :algorithm{_algorithm}
{
    std::cout<<"dfs constructor"<<std::endl;
    auto it = _inputs.begin();
    Rows = *it;
    Columns  = *(it+1);
    x_s = *(it+2);
    y_s = *(it+3);
    x_e = *(it+4);
    y_e =*(it+5);

}

std::vector<std::vector<char>> dfs::make_maze(){
    std::vector<std::vector<char>> maze(Rows,std::vector<char>(Columns , '0'));
    for(size_t i{}; i< maze.size() ; i++){
        for(size_t j{}; j< maze[i].size() ; j++){
            size_t num = (std::rand()) % 10;
            if(num>=7){
                maze[i][j] = '#';
            }
            else{
                maze[i][j] = '1';
            }
        }
    }
    for(size_t i{}; i<maze.size() ; i++){
        for(size_t j{}; j<maze[i].size() ; j++){
            std::cout<<maze[i][j]<<"  ";
        }
        std::cout<<std::endl;
    }
    return maze;
}
std::vector<std::vector<size_t>> dfs::dfs_maze(std::vector<std::vector<char>> maze){
    std::vector<std::vector<size_t>> ans(1,std::vector<size_t>(2 , '0')){x_s,y_s};

    bool arr_check[Rows][Columns];
    arr_check[x_s-1][y_s-1] = 1;
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