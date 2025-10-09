#include <bits/stdc++.h>
using namespace std;
class solution{
public: 
//brute force 
int maxl(string s){
    int n=s.length();;
    int maxlen=0;
    for(int i=0;i<n;i++){
        vector<int> hash(256,0);
        for(int j=i;j<n;j++){
            if(hash[s[j]]==1) break;
            hash[s[j]]=1;
            maxlen=max(maxlen,j-i+1);
        }
    }
    return maxlen;
}
//optimal
int solve(string str) {

  if(str.size()==0)
      return 0;
  int maxans = INT_MIN;
  unordered_set < int > set;
  int l = 0;
  for (int r = 0; r < str.length(); r++) // outer loop for traversing the string
  {
    if (set.find(str[r]) != set.end()) //if duplicate element is found
    {
      while (l < r && set.find(str[r]) != set.end()) {
        set.erase(str[l]);
        l++;
      }
    }
    set.insert(str[r]);
    maxans = max(maxans, r - l + 1);
  }
  return maxans;
}
};
int main() {
    
    return 0;
}