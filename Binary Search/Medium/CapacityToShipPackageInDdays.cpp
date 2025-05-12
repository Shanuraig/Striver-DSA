#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int check(vector<int>& weights, int mid){
        int day=1,load=0;
        for(int i=0;i<weights.size();i++){
            if(load+weights[i]>mid){
                day++;
                load=weights[i];
            }
            else{
                load+=weights[i];
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi=INT_MIN,sum=0;
        for(auto it : weights){
            maxi=max(maxi,it);
            sum+=it;
        }
        int req;
        int low=maxi,high=sum;
        while(low<=high){
            int mid=low+(high-low)/2;
            req=check(weights,mid);
            if(req<=days){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};