#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(vector<int>& b, int m, int k,int mid){
        int n=b.size();
        int cnt=0,nob=0;
        for(int i=0;i<n;i++){
            if(b[i]<=mid){
                cnt++;
            }
            else{
                nob+=cnt/k;
                cnt=0;
            }
        }
        nob+=cnt/k;
        return nob>=m ? true : false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        long long val=m*1LL*k*1LL;
        if(n<val) return -1;
        int maxi=INT_MIN,mini=INT_MAX;
        for(int it : bloomDay){
            maxi=max(maxi,it);
            mini=min(mini,it);
        }
        int low=mini,high=maxi;
        bool req;
        while(low<=high){
            int mid=low+(high-low)/2;
            req=check(bloomDay,m,k,mid);
            if(req){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};