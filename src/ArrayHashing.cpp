#include"../include/Solutions.hpp"
#include<vector>
#include<algorithm>
#include<iostream>
#include <unordered_set>

using namespace std;

bool ArrayHashing::hasDuplicate(vector<int>& nums) {
        unordered_set<int> s; 
        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i]) != s.end()){
                return true;
            }
            s.insert(nums[i]);
        }

        return false;
    }


bool ArrayHashing::isAnagram(string s, string t) {

        if(s.size()!=t.size()) return false;

        unordered_map<char,int> m;
        unordered_map<char,int> n;
        for(int i=0; i<s.size(); i++){
            m[s[i]]++;
            n[t[i]]++;
        }

        for(int i=0; i<m.size(); i++){
            if(m[i] != n[i]) return false;
        }
        return true;
    }



vector<int> ArrayHashing::twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        for(int i = 0;i<nums.size();i++){
            int comp = target - nums[i];
            if(m.find(comp) != m.end()){
                return {m[comp], i};
            }
            m.insert({nums[i],i});
        }

        return {};
    }



vector<vector<string>> ArrayHashing::groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> ans;

        for (auto s: strs){
            unordered_map<char,int> count;
            for(auto c: s){
                count[c]++;
            }

        string key;

        vector<pair<char, int>> countVec(count.begin(), count.end());
        sort(countVec.begin(), countVec.end());

        for(auto pair : countVec){
            key += pair.first + to_string(pair.second);
        }

        ans[key].push_back(s);
        }
        
        vector<vector<string>> res;

        for(auto pair : ans){
            res.push_back(pair.second);
        }

        return res;
    }


vector<int> ArrayHashing::topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int i = 0;i < nums.size(); i++){
            m[nums[i]]++;
        }

        vector<vector<int>> freq(nums.size() + 1);
        vector<int> res;

        for(const auto& entry : m){
            freq[entry.second].push_back(entry.first);
        }

        for(int i = freq.size()-1; i>0; i--){
            for(int n: freq[i]){
                res.push_back(n);
                if(res.size() == k){
                    return res;
                }
            }
        }
        return res;
    }




string ArrayHashing::encode(vector<string>& strs) {
        string res = "";
        for(int i = 0;i<strs.size();i++){
            res = res + "~" + strs[i];
        }

        if(strs.size() == 0){
            return res;
        }


        res = res.substr(1,res.size()-1);
        res = res + '~';

        return res;
    }

vector<string> ArrayHashing::decode(string s) {
        vector<string> ret;
 
        int i = 0;
        while(i<s.size()){
            if (s == ""){
                ret.push_back(s);
            }
            string num = "";

            while(s[i] != '~'){
                num = num + s[i];
                i++;
            }
            i++;
            ret.push_back(num);
        }
        return ret;
    }



vector<int> ArrayHashing::productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> rtl(nums.size(), 1);
        
        int pre = 1;
        
        for(int i = 0; i<nums.size(); i++){
            rtl[i] = pre;
            pre = pre * nums[i];
        }
        int post = 1;
        for(int i = n-1; i>=0; i--){
            rtl[i] = rtl[i] * post;
            post = post * nums[i];
        }
        return rtl;
    }


bool ArrayHashing::isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,unordered_set<char>> rows;
        unordered_map<int,unordered_set<char>> cols;
        unordered_map<int,unordered_set<char>> boxes;

        for(int row = 0; row<9;row++){
            for(int col=0;col<9;col++){
                char cell = board[row][col];
                if (cell == '.'){
                    continue;
                }
                if(rows[row].count(cell) || cols[col].count(cell) || boxes[(row/3)*3 + col/3].count(cell)){
                    return false;
                }

                cols[col].insert(cell);
                rows[row].insert(cell);
                boxes[(row/3)*3 + col/3].insert(cell);
            }      
        }

        return true;
    }


int ArrayHashing::longestConsecutive(vector<int>& nums) {
        unordered_set<int> n_set(nums.begin(), nums.end());
        int longest = 0;

        for(int num : n_set){
            if(n_set.find(num-1) == n_set.end()){
                int len = 1;
                while(n_set.find(num+len) != n_set.end()){
                    len++;
                }
                longest = max(len, longest);
            }
        }
        return longest;
    }

