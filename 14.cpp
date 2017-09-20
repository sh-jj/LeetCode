class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string ans="";
        if (n==0) return ans;
        if (strs[0]=="") return ans;
        for (int i=0;i<strs[0].size();i++)
        {
            for (int j=1;j<n;j++)
                if (i>strs[j].size()||strs[j][i]!=strs[j-1][i])
                {
                    return ans;
                }
            ans+=strs[0][i];
        }
        return ans;
    }
};
