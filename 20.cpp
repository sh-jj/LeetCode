class Solution {
public:
    bool isValid(string s) {
        int n=s.length();
        char q[n+1];
        int ls=0;
        for (int i=0;i<n;i++)
        {
            if (s[i]=='(') q[++ls] = ')'; 
            if (s[i]=='{') q[++ls] = '}';
            if (s[i]=='[') q[++ls] = ']';
            if (s[i]==')'||s[i]=='}'||s[i]==']')
                if (ls&&q[ls]==s[i]) ls--;
                    else return false;
        }
        return ls==0;
    }
};
