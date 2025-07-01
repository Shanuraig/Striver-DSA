#include<bits/stdc++.h>
using namespace std;
void printsubsequence(int idx , vector<int> &arr ,vector<int> &nums , int n){
    if(idx==n){
        for(auto it : arr){
            cout<<it<<" ";
        }
        cout<<endl;
        return;
    }
    arr.push_back(nums[idx]);
    printsubsequence(idx+1,arr,nums,n);
    arr.pop_back();
    printsubsequence(idx+1,arr,nums,n);
}
int main(){
    vector<int> nums={3,1,2};
    vector<int> ans;
    int n=nums.size();
    printsubsequence(0,ans,nums,n);
}