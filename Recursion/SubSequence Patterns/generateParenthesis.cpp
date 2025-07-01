#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> result;
    bool isvalid(string &curr){
        stack<char> st;
        for(auto it : curr){
            if(it=='(') st.push(it);
            else { 
                if(st.empty()) return false;
                st.pop();
            }
        }
        return st.empty();
       /* int count=0;
        for(auto it : curr){
            if(it=='(') count++;
            else count--;
            if(count<0) return false;
        }
        return count==0;*/
    }
    //better approach can be by removing the isvalid function and adding safety checks  
    void solve(string curr , int n , int open , int close){
        if(curr.length()==2*n){
            /*
            if(isvalid(curr)){
                }
                */ 
            result.push_back(curr);
            return;
        }
        if(open<n){
            curr.push_back('(');
            solve(curr,n,open,close);
            curr.pop_back();
        }
        if(close<open){
            curr.push_back(')');
            solve(curr,n,open,close);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        int open=0,close=0;
        string curr="";
        solve(curr,n,open,close);
        return result;
    }   
};