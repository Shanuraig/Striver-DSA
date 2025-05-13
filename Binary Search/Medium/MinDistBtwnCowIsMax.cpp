#include<bits/stdc++.h>
using namespace std;
class solution {
public : 
bool check(vector<int> &nums , int mid , int cows){
    int n=nums.size();
    int count=1,last=nums[0];
    for(int i=1;i<n;i++){
        if(nums[i]-last>=mid){
        count++;
        last=nums[i];
        }
    }
    return count>=cows;
}
int minDistanceBetweenCowIsMax(vector<int> &nums , int cows){
    int n=nums.size();
    int ans=0;
    int mini=INT_MAX,maxi=INT_MIN;
    for(auto it : nums){
        mini=min(mini,it);
        maxi=max(maxi,it);
    }
    int low=1,high=maxi-mini;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(check(nums,mid,cows)){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}
};