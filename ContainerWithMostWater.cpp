class Solution {
public:
    int maxArea(vector<int>& height) {
     int l=0;
     int r=height.size()-1;
     int m=0;
     while(l<r){
        int lh=height[l];
        int rh=height[r];
        int minh=min(lh,rh);
        m=max(m,minh*(r-l));
        if(lh<rh)l++;
        else{
            r--;
        }
     } 
     return m;
    }
};
