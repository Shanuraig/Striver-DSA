#include <bits/stdc++.h>
using namespace std;
//brute force 
vector<vector<int>> threesum(vector<int> &nums){
    int n=nums.size();
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if((nums[i]+nums[j]+nums[k])==0){
                    vector<int> temp={nums[i],nums[j],nums[k]};
                    sort(begin(temp),end(temp));
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(begin(st),end(st));
    return ans;
}
//Better O(N*N)
vector<vector<int>> threesum2(vector<int> &nums){
    int n=nums.size();
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        set<int> h;
        for(int j=i+1;j<n;j++){
            int third=-(nums[i]+nums[j]);
            if(h.count(third)){
                vector<int> temp={nums[i],nums[j],nums[third]};
                sort(begin(temp),end(temp));
                st.insert(temp);
            }
            h.insert(nums[j]);
        }
    }
    vector<vector<int>> ans(begin(st),end(st));
    return ans;
}
//optimal 

int main() {
    vector<int> nums={-1,0,1,2,-1,-4};
    vector<vector<int>> res=threesum(nums);
    for(auto it : res){
        for(auto num:it){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    return 0;
}