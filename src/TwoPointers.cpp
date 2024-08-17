#include"../include/TwoPointers.hpp"
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

std::vector<int> TwoPointers::twoSum(const std::vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;
        int n = 67;

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

std::vector<std::vector<int>> TwoPointers::threeSum(std::vector<int>& nums) {
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
bool TwoPointers::isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;

        while(l<r){
            while(!isalnum(s[l]) && l<r){
                l++;
            }
            while(!isalnum(s[r]) && l<r){
                r--;
            }
            if(tolower(s[l]) != tolower(s[r])){
                return false;
            }
            l++;
            r--;
        }
        return true;
}


int TwoPointers::maxArea(vector<int>& heights) {
    int max_val = 0;
    int l = 0;
    int r = heights.size() - 1;
    while(r < heights.size() & l < heights.size()-1)
    {
        int val = (r-l) * min(heights[r],heights[l]);

        max_val = max(max_val, val);

        if(heights[r]>=heights[l]){
            l++;
        }
        else{
            r--;
        }

    }   

    return max_val;
}


int TwoPointers::trap(vector<int>& height) {
    if (height.empty()) return 0;


    int l = 0;
    int r = height.size() - 1;
    int left_max = height[l];
    int right_max = height[r];
    int sum = 0;

    while(l<r){
        if(left_max<right_max){
            l++;
            left_max = max(left_max, height[l]);
            sum += left_max - height[l];
        }
        else{
            r--;
            right_max = max(right_max, height[r]);
            sum += right_max - height[r];
        }
    }

    return sum;
}


