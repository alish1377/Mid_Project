#include "BFS.h"

bfs::Node::Node(int x_s , int y_s){
    this->x = x_s;
    this->y = y_s;
}

bfs::bfs(std::shared_ptr<Node>proot , std::vector<std::vector<char>>_maze , std::array<int,4> _inputs)
    : maze(_maze)
{
    std::cout<<"bfs constructor"<<std::endl;
    this->proot = proot;
    auto it = _inputs.begin();
    x_s = *(it);
    y_s = *(it+1);
    x_e = *(it+2);
    y_e =*(it+3);
    Rows = maze.size();
    Columns = maze[0].size();
}


void bfs::bfs_maze(std::vector<std::vector<char>> maze){
    std::vector<std::shared_ptr <Node>> root ;
    root.push_back(proot);
    all_nodes.push_back(proot);

    if(x_s < 0 || x_s > Rows-1 ||  y_s < 0 || y_s > Columns-1)
    {
        std::cout<<"\033[1;31m";
        std::cout<<"Input is out of maze range"<<std::endl;
        std::cout<<"\033[1;39m";
    }
    else if(x_e < 0 || x_e > Rows-1 ||  y_e < 0 || y_e > Columns-1)
    {
        std::cout<<"\033[1;31m";
        std::cout<<"Output is out of maze range"<<std::endl;
        std::cout<<"\033[1;39m";
    }
    else if (maze[x_s][y_s] == '#' || maze[x_e][y_e] == '#')
    {
        std::cout<<"\033[1;31m";
        std::cout<<"Inputs or Outputs are wall(#)"<<std::endl;
        std::cout<<"\033[1;39m";
    }
    else{
        make_bfs_tree(root);
        Path_result();
    }
}

void bfs::make_bfs_tree(std::vector<std::shared_ptr <Node>>level_node){
    std::vector<std::shared_ptr <Node>> level;
    int check_ans{};
    for(size_t j{}; j < level_node.size() ; j++){
        int child_i{};
        int coordinate[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        int check;
        for (int i = 0; i < 4; i++)
        {
            int x{};
            int y{};
            x = static_cast<int>(level_node[j]->x) + coordinate[i][0];
            y = static_cast<int>(level_node[j]->y) + coordinate[i][1];
            for (size_t k = 0; k < all_nodes.size(); k++)
            {
                if(all_nodes[k]->x == x &&  all_nodes[k]->y == y){
                    check = 1;
                    break;
                }
            }
            if(x < 0 || x >= Rows || y < 0 || y >= Columns){
                continue;
            }
            else if(maze[x][y] == '#')
                continue;
            else if(check==1){
                check=0;
                continue;
            }
            else{
                check_ans =1;
                auto check_node{std::make_shared<bfs::Node>(x,y)};
                check_node->x = x;
                check_node->y = y;
                check_node->pparent = level_node[j];
                level_node[j]->children[child_i] = check_node;
                all_nodes.push_back(check_node);
                level.push_back(check_node);
                child_i++;
            }
            if(level[level.size()-1]->x == x_e && level[level.size()-1]->y == y_e )
            {
                end_node = level[level.size()-1];
                break;
            }
        }
        if(end_node != nullptr)
            break;
    }
    if(end_node == nullptr && check_ans==1){
        make_bfs_tree(level);
    }
    else if(end_node != nullptr && check_ans==1)
       return;
}

void bfs::Path_result(){
    if(all_nodes[all_nodes.size()-1]->x != x_e || all_nodes[all_nodes.size()-1]->y != y_e ){
        std::cout<<"\033[1;31m";
        std::cout<<"Sorry\nThese coordinates that you choose have no answere"<<std::endl;
        std::cout<<"\033[1;39m";
    }
    else{
        while(end_node){
            result_path.push_back(end_node);
            end_node = end_node->pparent;
        }
        show();
    }
}

void bfs::show(){
    maze[x_s][y_s]='S';
    maze[x_e][y_e]='E';
    std::cout<<"\033[1;32m";
    std::cout<<"Path of BFS algorithm is:  "<<std::endl;
    std::cout<<"\033[1;39m";
    std::cout<<"Start point: ";
    for (size_t i{result_path.size()-1}; i > 0; i--)
    {
        std::cout<<"("<<result_path[i]->x <<","<<result_path[i]->y <<")"<<std::endl;
    }
    std::cout<<"End point: "<<"("<<result_path[0] ->x <<","<<result_path[0]->y<<")"<<std::endl;
    std::cout<<"\033[0m";
    for (size_t i = 0; i < maze.size(); i++)
    {
        for (size_t j = 0; j < maze[i].size(); j++)
        {
            int check = 0;
            for (size_t k{}; k < result_path.size() ; k++){
                if( (result_path[k] -> x) == static_cast<int>(i) && (result_path[k] -> y) == static_cast<int>(j) ){
                    check = 1;
                    break;
                }
            }
            if(check==1){
                std::cout<<"\033[1;45m"<<maze[i][j]<<" "<<"\033[0m";
            }
            else
                std::cout<<maze[i][j]<<" ";

        }
        std::cout<<std::endl;
    }
}
