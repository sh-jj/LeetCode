class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length()*2+1;
        char a[n];
        int w=-1;
        for (int i=0;i<s.length();i++)
        {
            a[++w]='#';
            a[++w]=s[i];
        }
        a[++w]='#';
        int f[n];
        w=1;f[0]=0;
        for (int i=1;i<n;i++)
        {
            f[i]=0;
            if (w+f[w]>=i)
            {
                int j=w*2-i;
                if (i+f[j]<=w+f[w]) f[i]=f[j];
                    else f[i]=w+f[w]-i;
            }
            
            for (;i-(f[i]+1)>=0&&i+(f[i]+1)<n&&a[i-(f[i]+1)]==a[i+(f[i]+1)];f[i]++);
            if (i+f[i]>w+f[w]) w=i;
        }
        
        string ans;
        w=0;
        for (int i=0;i<n;i++)
            if (f[i]>f[w]) w=i;
        for (int i=w-f[w];i<=w+f[w];i++)
            if (i&1) ans= ans + a[i];
        return ans;
    }
};