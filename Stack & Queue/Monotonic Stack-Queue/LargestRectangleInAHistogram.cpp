#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        int res = 0;

        for (int i = 0; i <= n; i++) {
            int cur = (i == n ? 0 : nums[i]);
            while (!st.empty() && cur < nums[st.top()]) {
                int element = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                res = max(res, nums[element] * (nse - pse - 1));
            }
            st.push(i);
        }

        return res;
    }
};

int main() {
    
    return 0;
}