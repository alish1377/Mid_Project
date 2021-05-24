#include "BFS.h"

bfs::bfs(std::vector<std::vector<char>>_maze , std::array<int,4> _inputs)
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

void bfs::bfs_maze(std::vector<std::vector<char>> maze){
    std::shared_ptr <Node> p;
    p->x = x_s;
    p->y = y_s;
    make_bfs_tree(p);
}

void bfs::make_bfs_tree(std::shared_ptr<Node> proot){
    int coordinate[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    int check;
    for (int i = 0; i < 4; i++)
    {
        int x{};
        int y{};
        x = proot->x + coordinate[i][0];
        y = proot->y + coordinate[i][1];
        if(proot->pparent){
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
            std::shared_ptr<Node> check_node;
            check_node->x = x;
            check_node->y = y;
            check_node->pparent = proot;
            proot->children[i] = check_node;

        }
    }
    for (auto node = 0; node < proot->children.size(); node++)
    {
        make_bfs_tree(node);
    }
}
