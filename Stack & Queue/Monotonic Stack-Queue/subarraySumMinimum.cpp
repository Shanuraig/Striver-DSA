#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
int m=1e9+7;
vector<int> nse(vector<int> &arr){
    int n=arr.size();
    vector<int> res(n);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]>= arr[i]){
            st.pop();
        }
        res[i]=st.empty() ? n : st.top();
        st.push(i);
    }
    return res;
}
vector<int> pse(vector<int> &arr){
    int n=arr.size();
    vector<int> res(n);
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]> arr[i]){
            st.pop();
        }
        res[i]=st.empty() ? -1: st.top();
        st.push(i);
    }
    return res;
}
int sum(vector<int> &arr){
    int total=0;
    int n=arr.size();
    vector<int> pre=pse(arr);
    vector<int> nex=nse(arr);
    for(int i=0;i<n;i++){
        int left=i-pre[i];
        int right=nex[i]-i;
        total=(total+(left*right*1LL*arr[i])%m)%m;
    }
    return total;
}
};
int main() {
    
    return 0;
}