class Solution {
public:
    vector<string> ans;
    void dfs(int w,string now,int x)
    {
        if (w==0)
        {
            if (x==0) ans.push_back(now);
            return;
        }
        if (x) dfs(w-1,now+")",x-1);
        dfs(w-1,now+"(",x+1);
        
    }
    vector<string> generateParenthesis(int n) {
        
        dfs(n*2,"",0);
        return ans;
    }
};