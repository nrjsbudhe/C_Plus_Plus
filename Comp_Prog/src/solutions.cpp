#include"../include/solutions.hpp"

std::vector<int> Solution::twoSum(const std::vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;

        while(l<r){
            int currSum = numbers[l] + numbers[r];
            if(currSum > target){
                r--;
            }
            else if(currSum < target){
                l++;
            }
            else{
                return{l+1,r+1};
            }
        }
        return {};
}