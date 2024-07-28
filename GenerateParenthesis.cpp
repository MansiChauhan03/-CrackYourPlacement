class Solution {
public:
void solve(string &s,int n,int open,int close,vector<string> &ans)
{
    if(s.size() == 2*n)
    {
        ans.push_back(s);
        return ;
    }
    if(open<n)
    {
       s.push_back('(');
       solve(s,n,open+1,close,ans);
       s.pop_back();
    }
    if(close<open)
    {
        s.push_back(')');
        solve(s,n,open,close+1,ans);
        s.pop_back();
    }
}
    vector<string> generateParenthesis(int n) 
    {
        vector<string> ans;
        string s="";
        solve(s,n,0,0,ans);
        return ans;
    }
};
