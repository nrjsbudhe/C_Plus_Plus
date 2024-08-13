#include<iostream>
#include "include/solutions.hpp"
#include "include/checker.hpp"

int main()
{
    std::cout << "[MODULE] : CHECKER" << std::endl;
    Solution sol;
    Checker check;
    std::vector<int> numbers = {6,7,11,15};
    auto answer = sol.twoSum(numbers, 18);
    check.printAnswer(answer);
    std::cout << "The answer is: " << answer[0] << " " << answer[1] << std::endl;
    return 0;
}