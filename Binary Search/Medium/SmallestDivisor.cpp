#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(vector<int>& nums, int t , int mid){
        long long sum=0;
        for(int it : nums){
           sum+=ceil((double)it/(double)mid);
        }
        return sum<=(double)t;
    }
    int smallestDivisor(vector<int>& nums, int t) {
        int maxi=INT_MIN;
        for(auto it : nums){
            maxi=max(maxi,it);
        }
        int low=1,high=maxi;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(nums,t,mid)){
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
};