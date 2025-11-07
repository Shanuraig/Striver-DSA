#include <bits/stdc++.h>
using namespace std;
int minimum(vector<int> nums){
    int n=nums.size();
    int i=0,j=n-1;
    int ans=INT_MAX;
    while(i<j){
        int mid=i+(j-i)/2;
        if(nums[i]<=nums[mid]){
            ans=min(ans,nums[i]);
            i=mid+1;
        }
        else{
            ans=min(ans,nums[mid]);
            j=mid-1;
        }
    }
    return ans;
}
int main() {
    vector<int> nums={3,4,5,6,7,0,1,2,3};
    int res=minimum(nums);
    cout<<res;
    return 0;
}