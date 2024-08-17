// test_solutions.cpp
#include "gtest/gtest.h"
#include "../include/Solutions.hpp"

TEST(TwoSumTest, HandlesPositiveInput) {
    Solution sol;
    std::vector<int> nums = {2, 7, 11, 15};
    std::vector<int> result = sol.twoSum(nums, 9);
    std::vector<int> expected = {0, 1};
    EXPECT_EQ(result, expected);
}

TEST(TwoSumTest, HandlesNegativeInput) {
    Solution sol;
    std::vector<int> nums = {-3, 4, 3, 90};
    std::vector<int> result = sol.twoSum(nums, 0);
    std::vector<int> expected = {0, 2};
    EXPECT_EQ(result, expected);
}