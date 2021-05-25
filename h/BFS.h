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
            Node(int, int);
    };
    bfs(std::shared_ptr<Node>root,std::vector<std::vector<char>> , std::array<int,4>);
    void bfs_maze(std::vector<std::vector<char>> maze);
    void make_bfs_tree(std::vector<std::shared_ptr <Node>>);
    void solve_bfs_tree();
    void Path_result();
    void show();
    
    std::shared_ptr<Node> proot;
    std::shared_ptr<Node> end_node{};
    std::vector<std::shared_ptr<Node>> result_path;
    std::vector<std::shared_ptr<Node>> level_node;
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

