#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lh(vector<int> &nums) {
        int n = nums.size();
        stack<int> st;
        int res = 0;
        for (int i = 0; i <= n; i++) {
            int cur = (i == n) ? 0 : nums[i];
            while (!st.empty() && nums[st.top()] > cur) {
                int h = nums[st.top()];
                st.pop();
                int pse = st.empty() ? -1 : st.top();
                int nse = i;
                res = max(res, h * (nse - pse - 1));
            }
            st.push(i);
        }
        return res;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<int> ps(m, 0);
        int maxarea = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') ps[j] += 1;
                else ps[j] = 0;
            }
            maxarea = max(maxarea, lh(ps));
        }
        return maxarea;
    }
};

int main() {
    
    return 0;
}