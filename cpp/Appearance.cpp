#include "Appearance.h"
#include "make_maze.h"



void appearance(){
    std::string algorithm{};
    int Row{};
    int Column{};
    int x_s{};
    int y_s{};
    int x_e{};
    int y_e{};
    std::cout<<"\033[1;35m"<<std::endl;
    std::cout<<"Enter #Rows of Maze: ";
    std::cout<<"\033[1;39m";
    std::cin>>Row;
    std::cout<<"\033[1;35m"<<std::endl;
    std::cout<<"Enter #Columns of Maze: ";
    std::cout<<"\033[1;39m";
    std::cin>>Column;
    std::vector<std::vector<char>> maze;
    maze = make_maze(Row , Column);
    std::cout<<"\033[1;32m"<<std::endl;
    std::cout<< "X_Start : ";
    std::cout<<"\033[1;39m";
    std::cin>> x_s;
    std::cout<<"\033[1;32m"<<std::endl;
    std::cout<< "Y_Start : ";
    std::cout<<"\033[1;39m";
    std::cin>> y_s;
    std::cout<<"\033[1;32m"<<std::endl;
    std::cout<< "X_End : ";
    std::cout<<"\033[1;39m";
    std::cin>> x_e;
    std::cout<<"\033[1;32m"<<std::endl;
    std::cout<< "Y_End : ";
    std::cout<<"\033[1;39m";
    std::cin>> y_e;
    std::cout<<"\033[0m"<<std::endl;
    std::cout<<"\033[1;33m";
    std::cout<<"Choose algorithms (bfs/dfs) :";
    std::cout<<"\033[1;39m";
    std::cin>>algorithm;
    std::cout<<"\033[0m";
    std::array<int,4> inputs ={x_s , y_s, x_e , y_e};
    if(algorithm == "dfs"){
        dfs d{maze , inputs};
        d.dfs_maze(maze);
        d.show();
    }
    //else if(algorithm == "bfs")
}