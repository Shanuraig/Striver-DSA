#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Previous Smaller Element
    vector<int> pse(vector<int> &arr){
        int n=arr.size();
        vector<int> res(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            res[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return res;
    }

    // Next Smaller Element
    vector<int> nse(vector<int> &arr){
        int n=arr.size();
        vector<int> res(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            res[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return res;
    }

    // Previous Greater Element
    vector<int> pge(vector<int> &arr){
        int n=arr.size();
        vector<int> res(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] < arr[i]) st.pop();
            res[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return res;
    }

    // Next Greater Element
    vector<int> nge(vector<int> &arr){
        int n=arr.size();
        vector<int> res(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            res[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return res;
    }

    long long sumSubarrayMins(vector<int>& arr) {
        long long total=0;
        int n=arr.size();
        vector<int> pre=pse(arr);
        vector<int> nex=nse(arr);
        for(int i=0;i<n;i++){
            long long left=i-pre[i];
            long long right=nex[i]-i;
            total=(total + (left*right * arr[i]));
        }
        return total;
    }

    long long sumSubarrayMaxs(vector<int>& arr) {
        long long total=0;
        int n=arr.size();
        vector<int> pre=pge(arr);
        vector<int> nex=nge(arr);
        for(int i=0;i<n;i++){
            long long left=i-pre[i];
            long long right=nex[i]-i;
            total=(total + (left*right * arr[i]));
        }
        return total;
    }

    long long subArrayRanges(vector<int>& arr) {
        return sumSubarrayMaxs(arr)-sumSubarrayMins(arr);
    }
};

int main() {
    
    return 0;
}