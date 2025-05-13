#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        //brute force approach t.c -> O(n)
       /*int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]<=k) k++;
            else break;
        }
        return k;
       */
        //optimal approach using binary search T.C -> O(log N)
        int low=0,high=arr.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int missing=arr[mid]-(mid+1);
            if(missing<k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low+k;
    }
};