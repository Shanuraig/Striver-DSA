#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
//fucntion to calculate total hours
long long hour(vector<int> &pile , int h){
    long long req=0;
    for(auto it : pile ){
        req+=ceil((double)it/(double)h);
    }
    return req;
}
//fucntion to calculate eating speed 
    int minEatingSpeed(vector<int>& piles, int h){
        long long hours=0;
        int maxi=INT_MIN;
        for(auto it : piles){
            maxi=max(maxi , it );
        }
        int low=1,high=maxi;
        while(low<=high){
            int mid=low+(high-low)/2;
            hours=hour(piles,mid);
            if(hours<=h){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};