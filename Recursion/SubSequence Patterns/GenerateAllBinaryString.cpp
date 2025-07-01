#include<bits/stdc++.h>
using namespace std;
class Solution{
public :
vector<string> result;
void solve(int n , string &curr){
    if(curr.length()==n){
        result.push_back(curr);
        return;
    }
    curr.push_back('0');
    solve(n,curr);
    curr.pop_back();
    curr.push_back('1');
    solve(n ,curr);
    curr.pop_back();
}
vector<string> generate(int n){
    string res="";
    solve(n,res);
    return result;
}
};
int main(){
    int n=4;
    Solution obj;
    vector<string> Binary= obj.generate(n);
    for(auto it : Binary){
        cout<<it<<" "<<endl;
    }
}