class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        int l=0,r=n;
        int sl=(n+m)/2;
        if (m<sl) l=sl-m;
        if (n>sl) r=sl;
        int tl,tr;
        for (;l<=r;)
        {
            tl=(l+r)>>1;
            tr=sl-tl;
            if ((tl==0||tr==m||nums1[tl-1]<=nums2[tr])&&(tr==0||tl==n||nums2[tr-1]<=nums1[tl])) break;
            if ((tl>0&&tr<m&&nums1[tl-1]>nums2[tr])) 
                r=tl-1;
                else l=tl+1;
        }
        if ((n+m)&1)
        {
            if (tr==m||(tl<n&&nums1[tl]<nums2[tr])) return nums1[tl];
            return nums2[tr];
        }
        else {
                double x=0;
                if (tr==0||(tl>0&&nums1[tl-1]>nums2[tr-1])) x+=nums1[tl-1];
                    else x+=nums2[tr-1];
                
                if (tr==m||(tl<n&&nums1[tl]<nums2[tr])) x+=nums1[tl];
                    else x+=nums2[tr];
                return x/2;
            }
    }
};