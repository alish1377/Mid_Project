#ifndef _BIDIRECTIONAL_BFS_
#define _BIDIRECTIONAL_BFS_

#include <iostream>
#include "BFS.h"


class bi_bfs : public bfs{
public:
    bi_bfs(std::shared_ptr<Node>,std::shared_ptr<Node>,std::vector<std::vector<char>>,std::array<int,4>);
    void bfs_maze(std::vector<std::vector<char>> maze);
    void start_bfs_tree(std::vector<std::shared_ptr <Node>>);
    void end_bfs_tree(std::vector<std::shared_ptr <Node>>);
    void Path_result();
    void show();
    std::vector<std::shared_ptr<Node>> all_nodes_2;
    std::shared_ptr<Node> start_node{};
    std::vector<std::shared_ptr<Node>> level_s_node;
    std::vector<std::shared_ptr<Node>> level_e_node;
    std::shared_ptr<Node> proot_2{};
};


#endif 