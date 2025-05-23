#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool bs(vector<int> &nums,int target){
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                return true;
            }
            else if (nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        for(int i=0;i<n;i++){
            if(bs(matrix[i],target)){
                return true;
            }
        }
    return false;
    }
};