#include<bits/stdc++.h>
using namespace std;
class Solution {
public :
    vector<vector<int>> result;
    void solve(vector<int> &nums , vector<int> &curr , int idx){
                if(idx>=nums.size()){
                result.push_back(curr);
                return;
            }
            curr.push_back(nums[idx]);
            solve(nums,curr,idx+1);
            curr.pop_back();
            solve(nums,curr,idx+1);
        }
        vector<vector<int>> powerset(vector<int> &nums){
            vector<int> res;
            solve(nums,res,0);
            return result;
}
};