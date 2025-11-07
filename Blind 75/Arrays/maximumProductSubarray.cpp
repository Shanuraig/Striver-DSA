#include <bits/stdc++.h>
using namespace std;
//brute force
int productB(vector<int> &nums){
    int n=nums.size();
    int p=1,maxp=INT_MIN;
    for(int i=0;i<n;i++){
        p=1;
        for(int j=i;j<n;j++){
            p*=nums[j];
            maxp=max(maxp,p);
        }
    }
    return maxp;
}
//optimal
int product(vector<int> &nums){
    int n=nums.size();
    int p=1,s=1,maxi=INT_MIN;
    for(int i=0;i<n;i++){
        if(p==0)p=1;
        if(s==0)s=1;
        p*=nums[i];
        s*=nums[n-i-1];
        maxi=max(maxi,max(p,s));
    }
    return maxi;
}
int main() {
    vector<int> nums={2,3,-2,4};
    int ans1=productB(nums);
    int ans2=product(nums);
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}