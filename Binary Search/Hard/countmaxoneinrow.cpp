#include<bits/stdc++.h>
using namespace std;
int lowerbound(vector<int> &arr,int x){
    int n=arr.size();
    int low=0,high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]>=x){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low;
}
int rowwithmaxone(vector<vector<int>> & arr){
    int n=arr.size();
    int m=arr[0].size();
    int idx=-1;
    int maxcount=0;
    for(int i=0;i<n;i++){
        int rowcount=m-lowerbound(arr[i],1);
        if(rowcount>maxcount){
            maxcount=rowcount;
            idx=i;
        }
    }
    return idx;
}