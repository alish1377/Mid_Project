#include <iostream>
#include "DFS.h"
#include "BFS.h"
#include <stdlib.h>
#include <stdio.h>
#include "Appearance.h"

int main(int argc, const char** argv) {
    std::string algorithm{};
    size_t Row{};
    size_t Column{};
    size_t x_s{};
    size_t y_s{};
    size_t x_e{};
    size_t y_e{};
    appearance(Row , Column , x_s , y_s , x_e , y_e ,algorithm);

    return 0;
}