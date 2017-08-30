class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int count[300];
        for (int i=0;i<300;i++) count[i]=-1;
        int ans=0,last=-1;
        for (int i=0;i<s.length();i++)
        {
            int x=s[i];
            if (count[x]>last)
            {
                last=count[x];
               
            } 
            if (i-last>ans) ans= i-last;
            count[x]=i;
        }
        return ans;
    }
};