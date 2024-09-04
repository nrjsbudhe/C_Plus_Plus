#ifndef SOLUTIONS_HPP
#define SOLUTIONS_HPP

#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

class TwoPointers {
public:
    std::vector<int> twoSum(const std::vector<int>& nums, int target);
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums);
    bool isPalindrome(std::string s);
    int maxArea(std::vector<int>& height);
    int trap(std::vector<int>& height);
};

class ArrayHashing {
public:
    bool hasDuplicate(std::vector<int>& nums);
    bool isAnagram(std::string s, std::string t);
    std::vector<int> twoSum(std::vector<int>& nums, int target);
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs);
    std::vector<int> topKFrequent(std::vector<int>& nums, int k);
    std::string encode(std::vector<std::string>& longUrl);
    std::vector<std::string> decode(std::string shortUrl);
    std::vector<int> productExceptSelf(std::vector<int>& nums);
    bool isValidSudoku(std::vector<std::vector<char>>& board);
    int longestConsecutive(std::vector<int>& nums);
};

/**
 *  @brief Graph class
 *  @details This class is an abstract class that contains the basic functions that a graph should have.
 *  Every graph class should inherit from this class.
 *  @param adjList: An unordered map that stores the adjacency list of the graph.
 *  @param create_graph: Creates a graph with weight.
 *  @param printGraph: print the graph.
 *  @param findShortestPath: A pure virtual function that finds the shortest path between two nodes.
 *
 */

class Graph {
    private:
        std::unordered_map<int, std::vector<int>> adjList;
    public:
        virtual void create_graph(int u, int v, int w);         //Graph with weight
        virtual void print_graph();
        virtual void findShortestPath(int start, int goal) = 0;
};

class BFS : public Graph {
    public:
        void findShortestPath(int start, int goal) override;
};



#endif // SOLUTIONS_HPP