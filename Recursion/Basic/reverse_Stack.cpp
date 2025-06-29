#include<bits/stdc++.h>
using namespace std;
void solve(stack<int> & st ,int x){
    if(st.empty()) {
        st.push(x);
        return;
    }
    int num=st.top();
    st.pop();
    solve(st,x);
    st.push(num);
}
void reverse(stack<int> & st){
    if(st.empty()) return;
    int num=st.top();
    st.pop();
    reverse(st);
    solve(st,num);
}