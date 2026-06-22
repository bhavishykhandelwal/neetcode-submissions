class Solution {
public:
    vector<string>ans;
    void solve(int open,int close,int n,string res){
        if(res.size()== 2*n){
            ans.push_back(res);
            return;
        }
        if(open<n){
            solve(open+1,close,n,res+'(');
        }
        if(close<open){
            solve(open,close+1,n,res+')');
        }
    }
    vector<string> generateParenthesis(int n) {
        
        solve(0,0,n,"");
        return ans; 
    }
};
