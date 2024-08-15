#include<iostream>
#include "include/solutions.hpp"
#include "include/checker.hpp"

int main()
{
    Solution sol;
    Checker check;

    std::vector<int> numbers = {6,7,11,15};
    auto answer = sol.twoSum(numbers, 18);
    check.printAnswer(answer);

    std::vector<int> nums = {-1,0,1,2,-1,-4};
    auto answer1 = sol.threeSum(nums);
    _ASSERT(answer1.size() == 2);

    
    check.printAnswer(answer1);

    return 0;
}