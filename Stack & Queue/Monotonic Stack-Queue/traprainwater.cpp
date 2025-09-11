#include <bits/stdc++.h>
using namespace std;
class solution{
public:
vector<int> lm(vector<int> &nums , int n){
    vector<int> leftmax(n);
    leftmax[0]=nums[0];
    for(int i=1;i<n;i++){
        leftmax[i]=max(leftmax[i-1],nums[i]);
    }
    return leftmax;
}
vector<int> rm(vector<int> &nums , int n){
    vector<int> rightmax(n);
    rightmax[n-1]=nums[n-1];
    for(int i=n-2;i>=0;i--){
        rightmax[i]=max(rightmax[i+1],nums[i]);
    }
    return rightmax;
}
int trapwater(vector<int> &nums){
    int n=nums.size();
    vector<int> leftmax=lm(nums,n);
    vector<int> rightmax=rm(nums,n);
    int total=0;
    for(int i=0;i<n;i++){
        int h=min(leftmax[i],rightmax[i])-nums[i];
        total+=h;
    }
    return total;
}
};
int main() {
    
    return 0;
}