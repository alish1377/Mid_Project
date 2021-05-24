#include <iostream>
#include "DFS.h"
#include "BFS.h"
#include <stdlib.h>
#include <stdio.h>
#include "Appearance.h"
#include <thread>
#include <chrono>




int main(int argc, const char** argv) {
    std::cout<<"\033[1;36m"<<std::endl;
    std::cout<<"Welcome!!\n"<<"Please Enter some information about maze and algorithms"<<std::endl;
    appearance();
    /*std::cout<<"salam"<<std::endl;
    a.push_back(std::vector<size_t> {1,2});
    a.push_back(std::vector<size_t> {2,2});
    a.push_back(std::vector<size_t> {21,2});
    a.push_back(std::vector<size_t> {32,2});
    a.push_back(std::vector<size_t> {11,2});
    a.push_back(std::vector<size_t> {322,3});
    for (auto it{a.begin()}; it<a.end() ; it++){
        if(*it == std::vector<size_t> {32,2}){
            a.erase(it);
            break;
        }
    }
    for(size_t i{}; i<a.size() ; i++){
        for(size_t j{}; j<a[i].size() ; j++){
            std::cout<<a[i][j]<<"  ";
        }
        std::cout<<std::endl;
    }*/

    return 0;
}