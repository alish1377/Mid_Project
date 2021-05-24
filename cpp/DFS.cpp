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
    check_maze(x_s,y_s);
}

void dfs::check_maze(int x_temp , int y_temp){
    int coordinate[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    int check;
    for (int i = 0; i < 4; i++)
    {
        if(temp_ans[(temp_ans.size())-1] == std::vector<int>{x_e , y_e}){
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
        std::cout<<x<<" "<<y<<std::endl;
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
    for (auto it{temp_ans.begin()}; it<temp_ans.end() ; it++){
        if(*it == std::vector<int> {32,2}){
            temp_ans.erase(it);
            break;
        }
    }
}
void dfs::show(){
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
            if(check==1){
                long int k{};
                while (k < 100000000)
                {
                    //std::cout<<"hello"<<std::endl;
                    k++;
                }
                //std::cout<<"salam"<<std::endl;
                std::cout<<"\033[1;45m"<<maze[i][j]<<" "<<"\033[0m";
            }
            else
                std::cout<<maze[i][j]<<" ";

        }
        std::cout<<std::endl;
    }

}