class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int l=0,r=height.size()-1;
        int h=0,ans=0;
        for (;l<r;)
        {
            h=min(height[l],height[r]);
            ans=max(ans,h*(r-l));
            for (;l<r&&height[l]<=h;l++);
            for (;r>l&&height[r]<=h;r--);
        }
        
        return ans;
    }
};