class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.length(),m=p.length();
        bool f[n+1][m+1];
        memset(f,0,sizeof(f));
        f[0][0]=1;
        for (int fi=0;fi<=n;fi++)
            for (int fj=0;fj<=m;fj++)
            {
                if (!f[fi][fj]) continue;
                
                int i=fi-1,j=fj-1;
                
                if (i+1<n&&j+1<m&&(s[i+1]==p[j+1]||p[j+1]=='.'||(p[j+1]=='*'&&(s[i+1]==p[j]||p[j]=='.')))) f[fi+1][fj+1]=1;
                
                if (i+1<n&&j>0&&p[j]=='*'&&(s[i+1]==p[j-1]||p[j-1]=='.')) f[fi+1][fj]=1;
                
                if (j+2<m&&p[j+2]=='*') f[fi][fj+2]=1;
            }
        
        return f[n][m];
    }
};