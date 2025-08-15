#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    pair<int,int> singleNumber(vector<int> &nums){
        int xorr=0;
        for(auto it : nums){
            xorr^=it;
        }
        int right=xorr&(xorr-1)^xorr;
        int b1=0,b2=0;
        for(auto it : nums){
            if(it&right){
                b1^=it;
            }
            else{
                b2^=it;
            }
        }
        return {b1,b2};
    }
};
int main() {
    Solution obj1;
    vector<int> nums={2,4,2,6,3,7,7,3};
    pair<int,int> res=obj1.singleNumber(nums);
    cout<<res.first<<" "<<res.second<<endl;
    return 0;
}