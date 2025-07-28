#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int t[301];
bool solve(int idx , string &s , unordered_set<string>& D ){
    if(idx==s.length()){
        return true;
    }
    if(t[idx]!=-1) return t[idx];
    if(D.find(s)!=D.end()) return true;
    for(int i=1;i<s.length();i++){
        string temp=s.substr(idx,i);
        if(D.find(temp)!=D.end() && solve(idx+i,s,D)) return t[idx] = true;
    }
    return t[idx]=false;
}
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(t,-1,sizeof(t));
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        return solve(0,s,st);
    }
};