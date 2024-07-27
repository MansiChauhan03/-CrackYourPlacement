class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
     if(n==0){
        return tasks.size();
     }  
     int f[26]={0};
     for(char c: tasks){
        f[c-'A']++;
     }
     int m=0;
     int count=0;
     for(int i:f){
        if(i>m){
            m=i;
            count=1;
        }else if(i==m){
            count++;
        }
     }
        return max(static_cast<int>(tasks.size()), (m - 1) * (n + 1) + count);
    }
};
