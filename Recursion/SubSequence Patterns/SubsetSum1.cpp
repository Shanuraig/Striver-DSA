#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
vector<vector<int>> result; 
void solve(int idx , vector<int> &curr , vector<int> &nums){
        if(idx>=nums.size()){
            result.push_back(curr);
            return;
        }
        curr.push_back(nums[idx]);
        solve(idx+1,curr,nums);
        curr.pop_back();
        solve(idx+1,curr,nums);
}
vector<int> subsetsum(vector<int> &nums){
    vector<int> curr;
    solve(0,curr,nums);
    vector<int> res;
    for(auto &it : result){
        int sum=0;
        for(auto &ele : it){
            sum+=ele;
        }
        res.push_back(sum);
    }
    sort(begin(res),end(res));
    return res;
}
};
int main(){
    vector<int> nums={2,1,3};
    Solution obj1;
    vector<int> res=obj1.subsetsum(nums);
    for(int &it : res){
        cout<<it<<endl;
    }
}