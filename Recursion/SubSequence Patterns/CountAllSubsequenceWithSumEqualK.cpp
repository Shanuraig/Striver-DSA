#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
int count=0;
void solve(int sum ,int &count , int idx  , vector<int> &nums, int k ,int n){
    if(idx>=n){
        if(sum==k){
            count++;
        }
        return;
    }
    solve(sum+nums[idx],count,idx+1,nums,k,n);
    solve(sum,count,idx+1,nums,k,n);
}
int CA(vector<int> &nums ,int k ){
    int sum=0;
    int n=nums.size();
    solve(sum ,count,0,nums,k,n);
    return count;
}
};
int main(){
    vector<int> nums={1,2,1};
    int k=2;
    Solution obj1;
    int res=obj1.CA(nums,k);
    cout<<res;
}