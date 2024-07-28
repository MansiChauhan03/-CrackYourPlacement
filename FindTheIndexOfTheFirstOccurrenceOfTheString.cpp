SOLUTION:1

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.length();
        int m = haystack.length();
        

        if (n == 0) {
            return 0;
        }
        
        for (int i = 0; i <= m - n; i++) {
            if (haystack.substr(i, n) == needle) {
                return i;
            }
        }
        
        return -1;
    }
};


SOLUTION:2

class Solution {
public:
    int strStr(string haystack, string needle) {
        int index=0;
        for(int i=0;i<haystack.size();i++){
            if(haystack[i]==needle[0]){
                int j=0;
                for(j=1;j<needle.size();j++){
                    if(haystack[i+j]==needle[j]) continue;
                    else break;
                }
                if(j==needle.size()) return i;
            }

        }
        return -1;
    }
};
