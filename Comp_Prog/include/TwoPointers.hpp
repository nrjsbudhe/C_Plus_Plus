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

#endif // SOLUTIONS_HPP