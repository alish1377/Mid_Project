#include "bidirectional_bfs.h"

/*bi_bfs::Node_2::Node_2(int x_e , int y_e){
    this->x = x_e;
    this->y = y_e;
}*/
bi_bfs::bi_bfs(std::shared_ptr<Node>proot_start,std::shared_ptr<Node>proot_end,std::vector<std::vector<char>>_maze,std::array<int,4> _inputs)
    :bfs(proot_start ,_maze ,_inputs)
{
    this->proot_2 = proot_end;
}




void bi_bfs::bfs_maze(std::vector<std::vector<char>> maze){
    std::vector<std::shared_ptr <Node>> root_s ;
    root_s.push_back(proot);
    all_nodes.push_back(proot);
    all_nodes.push_back(proot_2);

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
        level_e_node.push_back(proot_2);
        start_bfs_tree(root_s);
        Path_result();
    }
}

void bi_bfs::start_bfs_tree(std::vector<std::shared_ptr <Node>>level_node){
    level_s_node.clear();
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
                level_s_node.push_back(check_node);
                child_i++;
            }
            for (size_t i{}; i < level_e_node.size(); i++)
            {
                if(level_e_node[i]->x ==x && level_e_node[i]->y ==y){
                    end_node_s = level_s_node[level_s_node.size()-1];
                    end_node_e = level_e_node[i];
                    break;
                }
            }
        }
        if(end_node_e != nullptr)
            break;
    }
    if(end_node_e == nullptr && check_ans==1){
        end_bfs_tree(level_e_node);
    }
    else if(end_node_e != nullptr && check_ans==1)
       return;
}

void bi_bfs::end_bfs_tree(std::vector<std::shared_ptr <Node>>level_node){
    level_e_node.clear();
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
                level_e_node.push_back(check_node);
                child_i++;
            }
            for (size_t i{}; i < level_s_node.size(); i++)
            {
                if(level_s_node[i]->x ==x && level_s_node[i]->y ==y){
                    end_node_s = level_s_node[level_s_node.size()-1];
                    end_node_e = level_e_node[i];
                    break;
                }
            }
        }
        if(end_node_e != nullptr)
            break;
    }
    if(end_node_e == nullptr && check_ans==1){
        start_bfs_tree(level_s_node);
    }
    else if(end_node_e != nullptr && check_ans==1)
       return;
}

void bi_bfs:: Path_result(){
    level_e_node.clear();
    level_s_node.clear();
    while(end_node_s){
        level_s_node.push_back(end_node_s);
        end_node_s = end_node_s->pparent;
    }
    while(end_node_e){
        level_e_node.push_back(end_node_e);
        end_node_e = end_node_e->pparent;
    }
    std::cout<<level_e_node.size()<<level_s_node.size()<<std::endl;
    for (size_t i = 0; i < level_s_node.size(); i++)
    {
        std::cout<< level_s_node[i]->x << "  "<< level_s_node[i]->y ;
    }
    std::cout<<std::endl;
    for (size_t j = 0; j < level_e_node.size(); j++)
    {
        std::cout<< level_e_node[j]->x << "  "<< level_e_node[j]->y ;
    }
    std::cout<<std::endl;
}