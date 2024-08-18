#include "gtest/gtest.h"
#include "../include/Solutions.hpp"

TEST(MODULE1_TWO_POINTERS, TwoSum) {
   // Two Sum
    TwoPointers sol;
    std::vector<int> numbers = {1,2,3,4};
    int n = 3;
    auto answer = sol.twoSum(numbers, 3);
    std::vector<int> expected = {1, 2};
    EXPECT_EQ(answer, expected);
}

TEST(MODULE1_TWO_POINTERS, ThreeSum) {
    // Three Sum
    TwoPointers sol;
    std::vector<int> nums = {-1,0,1,2,-1,-4};
    auto answer1 = sol.threeSum(nums);
    std::vector<std::vector<int>> expected = {{-1,-1,2},{-1,0,1}};
    EXPECT_EQ(answer1, expected);
}

TEST(MODULE1_TWO_POINTERS, IsPalandrome){
    // Is Palindrome
    TwoPointers sol;
    std::string s = "Was it a car or a cat I saw?";
    auto answer2 = sol.isPalindrome(s);
    bool expected = true;
    EXPECT_EQ(answer2, expected);   
}

TEST(MODULE1_TWO_POINTERS, MaxArea){
    // Max Area
    TwoPointers sol;
    std::vector<int> height = {1,7,2,5,4,7,3,6};
    auto answer3 = sol.maxArea(height);
    int expected = 36;
    EXPECT_EQ(answer3, expected);
}

TEST(MODULE1_TWO_POINTERS, TrappingRainWater){
    // Trapping Rain Water
    TwoPointers sol;
    std::vector<int> heights = {0,2,0,3,1,0,1,3,2,1};
    auto answer4 = sol.trap(heights);
    int expected = 9;
    EXPECT_EQ(answer4, expected);
}

TEST(MODULE2_ARRAY_HASHING, HasDuplicate){
    // Has Duplicate
    ArrayHashing sol;
    std::vector<int> nums = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    auto answer = sol.hasDuplicate(nums);
    bool expected = false;
    EXPECT_EQ(answer, expected);
}

TEST(MODULE2_ARRAY_HASHING, IsAnagram){
    // Is Anagram
    ArrayHashing sol;
    std::string s = "listen";
    std::string t = "silent";
    auto answer1 = sol.isAnagram(s, t);
    bool expected = true;
    EXPECT_EQ(answer1, expected);
}

TEST(MODULE2_ARRAY_HASHING, TwoSum){
    // Two Sum
    ArrayHashing sol;
    std::vector<int> numbers = {1,2,3,4};
    int n = 3;
    auto answer = sol.twoSum(numbers, 3);
    std::vector<int> expected = {0, 1};
    EXPECT_EQ(answer, expected);
}

TEST(MODULE2_ARRAY_HASHING, GroupAnagrams){
    // Group Anagrams
    ArrayHashing sol;
    std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto answer1 = sol.groupAnagrams(strs);
    std::vector<std::vector<std::string>> expected = {{"bat"},{"tan","nat"},{"eat","tea","ate"}};
    EXPECT_EQ(answer1, expected);
}

TEST(MODULE2_ARRAY_HASHING, TopKFrequent){
    // Top K Frequent
    ArrayHashing sol;
    std::vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    auto answer2 = sol.topKFrequent(nums, k);
    std::vector<int> expected = {1,2};
    EXPECT_EQ(answer2, expected);
}

TEST(MODULE2_ARRAY_HASHING, Encode){
    // Encode
    ArrayHashing sol;
    std::vector<std::string> longUrl = {"neet","code","love","you"};
    auto answer3 = sol.encode(longUrl);
    std::string expected = "neet~code~love~you~";
    EXPECT_EQ(answer3, expected);
}

TEST(MODULE2_ARRAY_HASHING, Decode){
    // Decode
    ArrayHashing sol;
    std::string shortUrl = "neet~code~love~you~";
    auto answer4 = sol.decode(shortUrl);
    std::vector<std::string> expected = {"neet","code","love","you"};
    EXPECT_EQ(answer4, expected);
}

TEST(MODULE2_ARRAY_HASHING, ProductExceptSelf){
    // Product Except Self
    ArrayHashing sol;
    std::vector<int> nums = {1,2,3,4};
    auto answer5 = sol.productExceptSelf(nums);
    std::vector<int> expected = {24,12,8,6};
    EXPECT_EQ(answer5, expected);
}

TEST(MODULE2_ARRAY_HASHING, IsValidSudoku){
    // Is Valid Sudoku
    ArrayHashing sol;
    std::vector<std::vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    auto answer6 = sol.isValidSudoku(board);
    bool expected = true;
    EXPECT_EQ(answer6, expected);
}

TEST(MODULE2_ARRAY_HASHING, LongestConsecutive){
    // Longest Consecutive
    ArrayHashing sol;
    std::vector<int> nums = {100, 4, 200, 1, 3, 2};
    auto answer7 = sol.longestConsecutive(nums);
    int expected = 4;
    EXPECT_EQ(answer7, expected);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}