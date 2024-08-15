#include"../include/solutions.hpp"
#include<vector>
#include<algorithm>

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

std::vector<std::vector<int>> Solution::threeSum(std::vector<int>& nums) {
        sort(nums.begin(),nums.end());
        std::vector<std::vector<int>> res;
        for(int i=0;i<nums.size();i++){
            if(nums[i] > 0) break;

            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }

            int l = i + 1; 
            int r = nums.size() - 1;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum>0){
                    r--;
                }
                else if(sum<0){
                    l++;
                }
                else{
                    res.push_back({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                    while(l<r && nums[l] == nums[l-1]){
                        l++;
                    }
                }
            }
        }

        return res;
}