#include <bits/stdc++.h>
using namespace std;
class StockSpanner {
public:
stack<pair<int,int>> res;
int idx;
    StockSpanner() {
        idx=-1;
    }
    int next(int price) {
        idx++;
        int ans=0;
        while(!res.empty() && res.top().first<=price){
            res.pop();
        }
        ans=idx-(res.empty()?-1:res.top().second);
        res.push({price,idx});
        return ans;
    }
};
int main() {
    
    return 0;
}