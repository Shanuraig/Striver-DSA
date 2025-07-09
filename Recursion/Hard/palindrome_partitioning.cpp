 #include<bits/stdc++.h>
 using namespace std;
 class Solution{
public:
vector<vector<string>> result;
    bool ispalindrome(string &s,int start , int end){
        while(start<=end){
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }
    void solve(int idx , string s , vector<string> &curr){
        if(idx>=s.length()){
            result.push_back(curr);
            return;
        }
        for(int i=idx;i<s.length();i++){
            if(ispalindrome(s,idx,i)){
                curr.push_back(s.substr(idx,i-idx+1));
                solve(i,s,curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> pp(string &s){
        vector<string> curr;
        solve(0,s,curr);
    }
 };
