#include "DFS.h"

dfs::dfs(std::vector<std::vector<char>>_maze , std::array<int,4> _inputs , std::string _algorithm)
    :algorithm{_algorithm}
    , maze(_maze)
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
std::vector<std::vector<int>> dfs::dfs_maze(std::vector<std::vector<char>> maze){
    check_maze(x_s,y_s);
}

void dfs::check_maze(int x_temp , int y_temp){
    temp_ans.push_back(std::vector <int> {x_temp , y_temp});
    comp_ans.push_back(std::vector <int> {x_temp , y_temp});
    if(temp_ans[(temp_ans.size())-1] == std::vector<int>{x_e , y_e})
        return;
    int coordinate[4][2] = {{0,-1},{-1,0},{0,1},{1,0}};
    int check;
        for (size_t i = 0; i < comp_ans.size(); i++)
        {
            if(comp_ans[i] == std::vector<int>{x_temp , y_temp}){
                check = 1;
                break;
            }
        }
    for (int i = 0; i < 4; i++)
    {
        x_temp = x_temp + coordinate[i][0];
        y_temp = y_temp + coordinate[i][1];
        if(x_temp <= 0 && x_temp > Rows && y_temp <= 0 && y_temp < Columns )
            continue;
        else if(maze[x_temp][y_temp] == '#')
            continue;
        else if(check==1){
            continue;
        }
        else
            check_maze(x_temp,y_temp);
    }
    for (auto it{temp_ans.begin()}; it<temp_ans.end() ; it++){
        if(*it == std::vector<int> {32,2}){
            temp_ans.erase(it);
            break;
        }
    }
}