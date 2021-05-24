#ifndef _BFS_H_
#define _BFS_H_

#include <iostream>
#include <memory>
#include "algorithm"
class bfs
{
public:
    class Node{
        public:
            int x;
            int y;
            std::shared_ptr <Node> pparent{nullptr};
            std::vector<std::shared_ptr <Node>> children = {nullptr , nullptr , nullptr , nullptr};
    };
    bfs(std::vector<std::vector<char>> , std::array<int,4>);
    void bfs_maze(std::vector<std::vector<char>> maze);
    void make_bfs_tree(std::shared_ptr<Node>);
    std::vector<std::shared_ptr <Node>> bfs_ans;
private:
    std::vector<std::vector<char>>maze;
    int Rows;
    int Columns;
    int x_s;
    int x_e;
    int y_s;
    int y_e;
};

#endif 

