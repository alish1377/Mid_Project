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
    proot->x = x_s;
    proot->y = y_s;
    //std::cout<<"salam"<<std::endl;
    std::vector<std::shared_ptr <Node>> root ;
    root.push_back(proot);
    all_nodes.push_back(proot);
    make_bfs_tree(root);
}

void bfs::make_bfs_tree(std::vector<std::shared_ptr <Node>>level_node){
    //std::cout<<"hello1"<<std::endl;
    //std::cout<<level_node[0]->y<<std::endl;
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
            //std::cout<<x<<std::endl;
            y = level_node[j]->y + coordinate[i][1];
            for (size_t k = 0; k < all_nodes.size(); k++)
            {
                if(all_nodes[k]->x == x &&  all_nodes[k]->y == y){
                    check = 1;
                    break;
                }
            }
            if(x < 0 || x >= Rows || y < 0 || y >= Columns)
                continue;
            else if(maze[x][y] == '#')
                continue;
            else if(check==1){
                std::cout<<"hello3"<<std::endl;
                check=0;
                continue;
            }
            else{
                auto check_node{std::make_shared<bfs::Node>(x,y)};
                check_node->x = x;
                check_node->y = y;
                check_node->pparent = level_node[j];
                level_node[j]->children[child_i] = check_node;
                all_nodes.push_back(check_node);
                level.push_back(check_node);
                child_i++;
                std::cout<<"hello2"<<std::endl;
            }
            if(level[level.size()-1]->x == x_e && level[level.size()-1]->y == y_e )
            {
                std::cout<<"hello3"<<std::endl;
                end_node = level[level.size()-1];
                break;
            }
        }
    }
    num++;
    if(num<3){
        //std::cout<<level.size()<<std::endl;
        make_bfs_tree(level);
    }
    /*if(end_node == nullptr){
        std::cout<<level.size()<<std::endl;
        make_bfs_tree(level);
        std::cout<<"hello4"<<std::endl;
    }*/
}

/*void bfs::Path_result(){
    std::shared_ptr<Node> temp_check;
    //std::cout<<end_node<<std::endl;
    //std::cout<<"hello1"<<std::endl;
    temp_check = end_node;
    while(temp_check){
        result_path.push_back(temp_check);
        temp_check = temp_check->pparent;
    }
    //std::cout<<result_path.size()<<std::endl;
    show();
}*/

/*void bfs::show(){
    //std::cout<<"hello2"<<std::endl;
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
}*/
