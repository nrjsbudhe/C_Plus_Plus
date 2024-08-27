#include"../include/Solutions.hpp"
#include<vector>
#include<algorithm>
#include<iostream>
#include <unordered_set>

void BFS::create_graph(float u, int v) {
        std::cout << "Creating graph with float and int" << std::endl;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

void BFS::printGraph() {
        std::cout << "Printing graph" << std::endl;
        for (const auto &node : adjList) {
                std::cout << node.first << " -> ";
                for (const int &neighbour : node.second) {
                    std::cout << neighbour << " ";
                }
                std::cout << std::endl;
        }
    }
