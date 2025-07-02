#include<bits/stdc++.h>
using namespace std;
class Solution{
public : 
vector<vector<int>> result;
void solve(int idx , int target , vector<int> &curr , vector<int> &nums){
    if(idx==nums.size()){
        if(target==0){
            result.push_back(curr);
        }
        return;
    }
    //take condition 
    if(nums[idx]<=target){
        curr.push_back(nums[idx]);
        solve(idx,target-nums[idx],curr,nums);
        curr.pop_back();
    }
    //not take condition
    solve(idx+1,target,curr,nums);
}
vector<vector<int>> findcombination(vector<int> &nums , int target){
    vector<int> curr;
    solve(0,target,curr,nums);
    return result;
}
};