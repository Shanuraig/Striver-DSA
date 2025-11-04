#include <bits/stdc++.h>
using namespace std;
//brute force
int maxsum(vector<int> &nums){
    int n=nums.size();
    int maxsum=0;
    int sum=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=nums[j];
            maxsum=max(maxsum,sum);
        }
    }
    return maxsum;
}
//optimal using kadens algorithm
int maxsumop(vector<int> &nums){
    int n=nums.size();
    int maxsum=INT_MIN;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=nums[i];
        maxsum=max(maxsum,sum);
        if(sum<0) sum=0;
    }
    return maxsum;
} 
int main() {
    int  n;
    cin>>n;;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int ans1=maxsum(nums);
    int ans2=maxsumop(nums);
    cout<<ans1<<" "<<ans2;
    return 0;
}