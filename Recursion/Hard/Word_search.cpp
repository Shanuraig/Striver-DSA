#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
int m,n;
vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
bool solve(vector<vector<char>> &board , int  i, int j, int idx , string &word){
    if(idx==word.length()) return true;
    if(i<0 || i>=m || j<0 || j>=n || board[i][j]=='$' || board[i][j]!=word[idx]) return false;
    char temp=board[i][j];
    board[i][j]='$';
    for(const auto &it :dir ){
        int newi=i+it.first;
        int newj=j+it.second;
        if(solve(board,newi,newj,idx,word)) return true;
    }
    board[i][j]=temp;
    return false;
}
bool wordsearch(vector<vector<char>> &board , string &word){
    m=board.size();
    n=board[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]==word[0] && solve(board,i,j,0,word)) return true;
        }
    }
    return false;
}
};