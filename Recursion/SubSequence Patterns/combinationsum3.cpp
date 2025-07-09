#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> result;
    void solve(int idx, int k, int n, vector<int>& curr) {
        if (k == 0 && n == 0) {
            result.push_back(curr);
            return;
        }
        for (int i = idx; i <= 9; i++) {
            if(i>n) break;
            curr.push_back(i);
            solve(i + 1, k - 1, n - i, curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;
        solve(1, k, n, curr);
        return result;
    }
};