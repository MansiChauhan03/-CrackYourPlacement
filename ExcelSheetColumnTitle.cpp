SOLUTION 1:
    
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string str="";
        
        while(columnNumber > 0){
            char ch = char(ceil((columnNumber-1)%26 + 65));
            str = ch+str;
            columnNumber = (columnNumber-1)/26;
        }
        return str;
    }
};

SOLUTION 2:

class Solution {
public:
    string convertToTitle(int n) {
        string ans = "";
        while(n>0){
            n--;
            int curr = n % 26;
            n = n/26;
            ans.push_back((char)(curr + 'A'));
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
