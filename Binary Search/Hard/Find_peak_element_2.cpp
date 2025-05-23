#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findmax(vector<vector<int>> &nums, int n , int m , int mid){
        int index=-1;
        int maxvalue=-1;
        for(int i=0;i<n;i++){
            if(nums[i][mid]>maxvalue){
                maxvalue=nums[i][mid];
                index=i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int low=0,high=m-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int rowindex=findmax(mat,n,m,mid);
            int left=mid-1>0? mat[rowindex][mid-1] : -1;
            int right=mid+1<m ? mat[rowindex][mid+1]:-1;
            if(mat[rowindex][mid]>left && mat[rowindex][mid]>right){
                return {rowindex,mid};
            }
            else if (mat[rowindex][mid]<left){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return {-1,-1};
    }
};