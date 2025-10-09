#include <bits/stdc++.h>
using namespace std;
class Solution{
public: 
//brute force 
int solvebrute(vector<int> &nums,int k){
    int n=nums.size();
    int maxl=0;
    for(int i=0;i<n;i++){
        unordered_set<int> st;
        for(int j=i;j<n;j++){
            st.insert(nums[j]);
            if(st.size()>k) break;
            maxl=max(maxl,j-i+1);
        }
    }
    maxl;
}
//optimal
int solveoptimal(vector<int> &nums , int k){
    unordered_map<int,int> mpp;
    int l=0,r=0,maxl=0,n=nums.size();
    while(r<n){
        mpp[nums[r]]++;
        if(mpp.size()>k){
            while(mpp.size()>k){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0) mpp.erase(nums[l]);
                l++;
            }
        }
        if(mpp.size()<=k){
            maxl=max(maxl,r-l+1);
        }
        r++;
    }
    return maxl;
}
};
int main() {
    
    return 0;
}