#include "make_maze.h"

std::vector<std::vector<char>>make_maze(size_t Rows , size_t Columns){
    std::vector<std::vector<char>> maze(Rows,std::vector<char>(Columns , '0'));
    for(size_t i{}; i< maze.size() ; i++){
        for(size_t j{}; j< maze[i].size() ; j++){
            int num = (std::rand()) % 100;
            if(num>=70){
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