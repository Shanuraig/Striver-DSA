#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        string res="";
        if(k==num.length()) return "0";
        for(int i=0;i<num.length();i++){
            while(!st.empty() && st.top()-'0'>num[i]-'0' && k>0){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k>0){
            st.pop();
            k--;
        }
        if(st.empty()) return "0";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        while(res.length()!=0 && res.back()=='0'){
            res.pop_back();
        }
        reverse(begin(res),end(res));
        if(res.empty()) return "0";
        return res;
    }
};
int main() {
    
    return 0;
}