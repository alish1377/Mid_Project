#include "BFS.h"

bfs::bfs(std::vector<std::vector<char>>_maze , std::array<int,4> _inputs)
    : maze(_maze)
{
    std::cout<<"bfs constructor"<<std::endl;
    auto it = _inputs.begin();
    x_s = *(it);
    y_s = *(it+1);
    x_e = *(it+2);
    y_e =*(it+3);
    Rows = maze.size();
    Columns = maze[0].size();

}
bfs::bfs(std::shared_ptr<Node>proot){
    this->proot = proot;
}

void bfs::bfs_maze(std::vector<std::vector<char>> maze){
    proot->x = x_s;
    proot->y = y_s;
    std::vector<std::shared_ptr <Node>> root ;
    root.push_back(proot);
    make_bfs_tree(root);
}

void bfs::make_bfs_tree(std::vector<std::shared_ptr <Node>>level_node){
    std::vector<std::shared_ptr <Node>> level;
    for(size_t j{}; j < level_node.size() ; j++){
        int child_i{};
        int coordinate[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        int check;
        for (int i = 0; i < 4; i++)
        {
            int x{};
            int y{};
            x = level_node[j]->x + coordinate[i][0];
            y = level_node[j]->y + coordinate[i][1];
            if(level_node[j]->pparent){
                check = 1;
                break;
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
                std::cout<<"salam"<<std::endl;
                std::shared_ptr<Node> check_node;
                check_node->x = x;
                check_node->y = y;
                check_node->pparent = level_node[j];
                level_node[j]->children[child_i] = check_node;
                level.push_back(check_node);
                child_i++;
            }
            if(level[level.size()-1]->x == x_e && level[level.size()-1]->y == y_e )
            {
                end_node = level[level.size()-1];
                break;
            }
        }
        if(end_node == nullptr)
            make_bfs_tree(level);
        else
            break;
    }
    Path_result();
}

void bfs::Path_result(){
    std::shared_ptr<Node> temp_check;
    temp_check = end_node;
    while(temp_check){
        result_path.push_back(temp_check);
        temp_check = temp_check->pparent;
    }
    //std::cout<<result_path.size()<<std::endl;
    show();
}

void bfs::show(){
    //std::cout<<result_path.size()<<std::endl;
    for (size_t i = 0; i < maze.size(); i++)
    {
        for (size_t j = 0; j < maze[i].size(); j++)
        {
            int check = 0;
            for (size_t k; k < result_path.size() ; k++){
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
