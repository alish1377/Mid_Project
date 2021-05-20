#include "Appearance.h"


void appearance(size_t Row , size_t Column, size_t x_s , size_t y_s , size_t x_e , size_t y_e , std::string algorithm){
    std::cout<<"\033[1;36m"<<std::endl;
    std::cout<<"Welcome!!\n"<<"Please Enter some information about maze and algorithms"<<std::endl;
    std::cout<<"\033[1;35m"<<std::endl;
    std::cout<<"Enter #Rows of Maze: ";
    std::cout<<"\033[1;39m";
    std::cin>>Row;
    std::cout<<"\033[1;35m"<<std::endl;
    std::cout<<"Enter #Columns of Maze: ";
    std::cout<<"\033[1;39m";
    std::cin>>Column;
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
    std::cout<<"Choose algorthms (bfs/dfs) :";
    std::cout<<"\033[1;39m";
    std::cin>>algorithm;
    std::cout<<"\033[0m";
}