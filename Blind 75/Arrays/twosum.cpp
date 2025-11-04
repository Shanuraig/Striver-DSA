#include <bits/stdc++.h>
using namespace std;
//brute force
pair<int,int> twosum(vector<int> &nums , int target){
    int n=nums.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) continue;
            int sum=nums[i]+nums[j];
            if(sum==target) return {i,j};
        }
        return {};
    }
}
//optimal
pair<int,int> twosumop(vector<int> &nums , int target){
    int n=nums.size();
    unordered_map<int,int> mpp;
    for(int i=0;i<n;i++){
        int rem=target-nums[i];
        if(mpp.count(rem)) return {mpp[rem],i};
        mpp[nums[i]]=i;
    }
    return {};
}
int main() {
    vector<int> nums={2,7,11,15};
    pair<int,int> ans1=twosum(nums,9);
    cout<<ans1.first <<" "<<ans1.second<<endl;
    pair<int,int> ans2=twosumop(nums,9);
    cout<<ans2.first <<" "<<ans2.second<<endl;
    return 0;
}