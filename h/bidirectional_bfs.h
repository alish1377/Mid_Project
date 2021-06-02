#ifndef _BIDIRECTIONAL_BFS_
#define _BIDIRECTIONAL_BFS_

#include <iostream>
#include "bfs.h"


class bi_bfs : public bfs{
public:
    /*class Node_2{
        public:
            int x;
            int y;
            std::shared_ptr <Node_2> pparent{nullptr};
            std::vector<std::shared_ptr <Node_2>> children = {nullptr , nullptr , nullptr , nullptr};
            Node_2(int, int);
    };*/

    bi_bfs(std::shared_ptr<Node>,std::shared_ptr<Node>,std::vector<std::vector<char>>,std::array<int,4>);
    void bfs_maze(std::vector<std::vector<char>> maze);
    void start_bfs_tree(std::vector<std::shared_ptr <Node>>);
    void end_bfs_tree(std::vector<std::shared_ptr <Node>>);
    void Path_result();
    std::shared_ptr<Node> end_node_s{};
    std::shared_ptr<Node> end_node_e{};
    std::vector<std::shared_ptr<Node>> level_s_node;
    std::vector<std::shared_ptr<Node>> level_e_node;
    std::shared_ptr<Node> proot_2{};
};


#endif 