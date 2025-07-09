#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> result;
void solve(int idx , string &s , string &temp,unordered_map<char,string>&mp){
    if(idx>=s.length()){
        result.push_back(temp);
        return;
    }
    char ch=s[idx];
    string str=mp[ch];
    for(int i=0 ; i<str.length();i++){
        temp.push_back(str[i]);
        solve(idx+1,s,temp,mp);
        temp.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0) return {};
        string temp="";
        unordered_map<char,string> mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        solve(0,digits,temp,mp);
        return result;
    }
};