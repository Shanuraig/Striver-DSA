#include <bits/stdc++.h>
using namespace std;
int stock(vector<int> &nums){
    int profit=0;
    int n=nums.size();
    int mini=nums[0];
    for(int i=0;i<n;i++){
        int cost=nums[i]-mini;
        profit=max(profit,cost);
        mini=min(mini,nums[i]);
    }
    return profit;
}
int main() {
    vector<int> nums={7,1,5,3,6,4};
    int ans=stock(nums);
    cout<<ans<<endl;
    return 0;
}