#include<bits/stdc++.h>
using namespace std;
class Solution{
public : 
vector<vector<int>> result;
void solve( int idx , vector<int> &curr , vector<int> & nums,int s,int sum , int n){
    if(idx>=n){
        if(s==sum){
            result.push_back(curr);
        }
        return;
    }
    curr.push_back(nums[idx]);
    s+=nums[idx];
    solve(idx+1,curr,nums,s,sum,n);
    s-=nums[idx];
    curr.pop_back();
    solve(idx+1,curr,nums,s,sum,n);
}
vector<vector<int>> print(vector<int> &nums , int sum){
    vector<int> curr;
    int s=0;
    int n=nums.size();
    solve(0,curr,nums,s,sum,n);
    return result;
}
};
int main(){
    Solution obj1;
    vector<int> nums={1,2,1};
    int sum=2;
    vector<vector<int>> res=obj1.print(nums,sum);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
 }