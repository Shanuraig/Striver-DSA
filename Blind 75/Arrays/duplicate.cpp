#include <bits/stdc++.h>
using namespace std;
bool duplicate(vector<int> &nums){
    set<int> st;
    for(auto it : nums){
        st.insert(it);
    }
    return nums.size()!=st.size();
}
int main() {
    vector<int> nums={1,1,2,3,4,4};
    bool ans=duplicate(nums);
    if(ans==true) cout<<"True";
    else cout<<"false";
    return 0;
}