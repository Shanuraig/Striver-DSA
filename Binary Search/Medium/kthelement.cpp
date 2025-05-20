#include<bits/stdc++.h>
using namespace std;
class solution {
public : 
    int kthelement(vector<int> &nums1 , vector<int> &nums2 , int k){
        int n1=nums1.size();
        int n2=nums2.size();
        int n=n1+n2;
        vector<int> res(n);
        int i=0,j=0;
        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j]){
                res.push_back(nums1[i]);
                i++;
            }
            else{
                res.push_back(nums2[j]);
                j++;
            }
        }
        return res[k];
    }
};