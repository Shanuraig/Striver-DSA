#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> result;
    void solve(int idx,int target , vector<int> &curr , vector<int> &nums){
        
            if(target==0){
                result.push_back(curr);
                return;
            }
            for(int i=idx;i<nums.size();i++){
                if(i>idx && nums[i]==nums[i-1]) continue;
                if(nums[i]>target) break;
                curr.push_back(nums[idx]);
                solve(i+1,target-nums[i],curr,nums);
                curr.pop_back();
            }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        sort(begin(candidates),end(candidates));
        int sum=0;
        solve(0,target,curr,candidates);
        return result;
    }
};