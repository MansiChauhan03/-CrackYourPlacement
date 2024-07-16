#include <bits/stdc++.h>
using namespace std;

class Solution{
    public: 
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    if(m==0 || n==0){
        return 0;
    }
    sort(a.begin(),a.end());
    int mini=INT_MAX;
    int i=0;
    int j=m-1;
    while(j<n){
        int diff=a[j]-a[i];
        mini=min(mini,diff);
        i++;
        j++;
    }
    return mini;
    }   
};
