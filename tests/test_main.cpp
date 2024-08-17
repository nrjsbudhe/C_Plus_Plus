#include "gtest/gtest.h"
#include "../include/TwoPointers.hpp"

TEST(TwoSumTest, HandlesPositiveInput) {
   // Two Sum
    TwoPointers sol;
    std::vector<int> numbers = {1,2,3,4};
    int n = 3;
    auto answer = sol.twoSum(numbers, 3);
    std::vector<int> expected = {1, 2};
    EXPECT_EQ(answer, expected);
}

TEST(TwoSumTest, HandlesNegativeInput) {
    TwoPointers sol;
    std::vector<int> nums = {-3, 4, 3, 90};
    std::vector<int> result = sol.twoSum(nums, 0);
    std::vector<int> expected = {1, 3};
    EXPECT_EQ(result, expected);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}