#include <bits/stdc++.h>
using namespace std;
class solution{
public :
int solve(vector<int> &nums,int k){
    int n=nums.size();
    int zeros=0,l=0,r=0,maxl=0;
    while(r<n){
        if(nums[r]==0)zeros++;
        while(zeros>k){
            if(nums[l]==0)zeros--;
            l++;
        }
        maxl=max(maxl,r-l+1);
        r++;
    }
    return maxl;
}
};
int main() {
    
    return 0;
}