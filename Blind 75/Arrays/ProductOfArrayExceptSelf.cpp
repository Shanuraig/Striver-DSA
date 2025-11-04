#include <bits/stdc++.h>
using namespace std;
//brute force
vector<int> productbrute(vector<int> &nums){
    int n=nums.size();
    vector<int> res(n,1);
    for(int i=0;i<n;i++){
        int p=1;
        for(int j=0;j<n;j++){
            if(i==j) continue;
            p*=nums[j];
        }
        res[i]=p;
    }
    return res;
}
//optimal and space optimised
vector<int> product(vector<int> &nums){
    int n=nums.size();
    vector<int> res(n,1);
    //prefix
    for(int i=1;i<n;i++){
        res[i]=res[i-1]*nums[i-1];
    }
    //suffix
    int suffix=1;
    for(int i=n-2;i>=0;i--){
        suffix*=nums[i+1];
        res[i]*=suffix;
    }
    return res;
}
int main() {
    vector<int> nums={1,2,3,4};
    vector<int> res1=product(nums);
    vector<int> res2=productbrute(nums);

    for(auto it : res1){
        cout<<it<<" ";
    }
    cout<<endl;
    for(auto it : res2){
        cout<<it<<" ";
    }
    return 0;
}