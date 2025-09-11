#include <bits/stdc++.h>
using namespace std;

vector<int> nge(vector<int> &nums) {
    vector<int> res;
    stack<int> st;
    for (int i = nums.size() - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums[i]) {
            st.pop();
        }
        if (st.empty()) res.push_back(-1);
        else res.push_back(st.top());
        st.push(nums[i]);
    }
    reverse(res.begin(), res.end()); // reverse to match original order
    return res;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) cin >> nums[i];

    vector<int> ans = nge(nums);

    cout << "Next Greater Elements: ";
    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}
