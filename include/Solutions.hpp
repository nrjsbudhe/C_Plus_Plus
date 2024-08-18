#ifndef SOLUTIONS_HPP
#define SOLUTIONS_HPP

#include <vector>
#include <string>

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


#endif // SOLUTIONS_HPP