#include<iostream>
#include "../include/TwoPointers.hpp"
#include "../include/checker.hpp"

int main()
{
    TwoPointers sol;
    Checker check;

    // Is Palindrome
    std::string s = "Was it a car or a cat I saw?";
    auto answer2 = sol.isPalindrome(s);
    check.printAnswer(answer2);

    // Two Sum
    std::vector<int> numbers = {1,2,3,4};
    int n = 3;
    auto answer = sol.twoSum(numbers, 3);
    check.printAnswer(answer);

    // Three Sum
    std::vector<int> nums = {-1,0,1,2,-1,-4};
    auto answer1 = sol.threeSum(nums);
    check.printAnswer(answer1);

    // Max Area
    std::vector<int> height = {1,7,2,5,4,7,3,6};
    auto answer3 = sol.maxArea(height);
    check.printAnswer(answer3);

    // Trapping Rain Water
    std::vector<int> heights = {0,2,0,3,1,0,1,3,2,1};
    auto answer4 = sol.trap(heights);
    check.printAnswer(answer4);

    return 0;
}