#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
bool canfill(int row,int col,vector<string> &curr,int n){
    int drow=row;
    int dcol=col;
    while(row>=0 && col>=0){
        if(curr[row][col]=='Q'){
            return false;
        }
        row--;
        col--;
    }
    col=dcol;
    row=drow;
    while(col>=0){
         if(curr[row][col]=='Q'){
            return false;
        }
        col--;
    }
    col=dcol;
    while(row<n && col>=0){
        if(curr[row][col]=='Q'){
            return false;
        }
        row++;
        col--;
    }
    return true;
}
void solve(int col , vector<string> &curr , vector<vector<string>> & result , int n){
        if(col==n){
            result.push_back(curr);
            return;
        }
        for(int row=0;row<n;row++){
            if(canfill(row,col,curr,n)){
                curr[row][col]='Q';
                solve(col+1,curr,result,n);
                curr[row][col]='.';
            }
        }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> curr(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            curr[i]=s;
        }
        solve(0,curr,result,n);
        return result;
    }
};