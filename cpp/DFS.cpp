#include "DFS.h"

dfs::dfs(std::vector<std::vector<char>>_maze , std::array<int,4> _inputs)
    : maze(_maze)
{
    std::cout<<"dfs constructor"<<std::endl;
    auto it = _inputs.begin();
    x_s = *(it);
    y_s = *(it+1);
    x_e = *(it+2);
    y_e =*(it+3);
    Rows = maze.size();
    Columns = maze[0].size();

}
void dfs::dfs_maze(std::vector<std::vector<char>> maze){
    temp_ans.push_back(std::vector <int> {x_s , y_s});
    comp_ans.push_back(std::vector <int> {x_s , y_s});
    if(x_s < 0 || x_s > Rows-1 ||  y_s < 0 || y_s > Columns-1)
    {
        std::cout<<"\033[1;31m";
        std::cout<<"Input is out of maze range"<<std::endl;
        std::cout<<"\033[1;39m";
    }
    else if (maze[x_s][y_s] == '#' || maze[x_e][y_e] == '#')
    {
        std::cout<<"\033[1;31m";
        std::cout<<"Inputs or Outputs are wall(#)"<<std::endl;
        std::cout<<"\033[1;39m";
    }
    else{
        check_maze(x_s,y_s);
        show();
    }
}

void dfs::check_maze(int x_temp , int y_temp){
    int coordinate[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    int check;
    for (int i = 0; i < 4; i++)
    {
        if(temp_ans[(temp_ans.size())-1] == std::vector<int>{x_e , y_e}){
            check_ans=1;
            return;
        }
        int x{};
        int y{};
        x = x_temp + coordinate[i][0];
        y = y_temp + coordinate[i][1];
        for (size_t i = 0; i < comp_ans.size(); i++)
        {
            if(comp_ans[i] == std::vector<int>{x , y}){
                check = 1;
                break;
            }
        }
        if(x < 0 || x >= Rows || y < 0 || y >= Columns)
            continue;
        else if(maze[x][y] == '#')
            continue;
        else if(check==1){
            check=0;
            continue;
        }
        else{
            temp_ans.push_back(std::vector <int> {x , y});
            comp_ans.push_back(std::vector <int> {x , y});
            check_maze(x,y);
        }
    }
    if(check_ans==1)
        return;
    for (auto it{temp_ans.end()-1}; it>temp_ans.begin()-1 ; it--){
        if(*it != std::vector(x_temp , y_temp)){
            temp_ans.erase(it);
            break;
        }
    }
}
void dfs::show(){
    for (size_t i = 0; i < temp_ans.size(); i++)
    {
        std::cout<<temp_ans[i][0]<<" "<<temp_ans[i][1]<<std::endl;
    }
    if(check_ans==1){
        for (size_t i = 0; i < maze.size(); i++)
        {
            for (size_t j = 0; j < maze[i].size(); j++)
            {
                int check = 0;
                for (auto it{temp_ans.begin()}; it<temp_ans.end() ; it++){
                    if(*it ==std::vector<int> {static_cast<int>(i),static_cast<int>(j)}){
                        check = 1;
                        break;
                    }
                }
                if(check==1)
                    std::cout<<"\033[1;45m"<<maze[i][j]<<" "<<"\033[0m";
                else{
                    //std::cout<<"\033[1;45m"<<maze[i][j]<<" "<<"\033[0m";
                    std::cout<<maze[i][j]<<" ";
                }
            }
            std::cout<<std::endl;
        }
    }
    else{
        std::cout<<"\033[1;31m";
        std::cout<<"Sorry\nThese coordinates that you choose have no answere"<<std::endl;
        std::cout<<"\033[1;39m";
    }
}