#include<bits/stdc++.h>
using namespace std;
const int M=1e9+7;
int findpower(long long a, long long b){
    if(b==0) return 1;
    long long half=findpower(a,b/2);
    long long result=(half*half)%M;
    if(b%2==1) result=(result*a)%M;
    return result;
}   
int count(long long n){
    return findpower(5,(n+1)/2)*findpower(4,n/2)%M;
}