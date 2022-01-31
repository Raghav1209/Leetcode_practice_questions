class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int x = n+m;
        vector<float> nums3(x);
        
        merge(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),nums3.begin());
        
        int l = 0;
        int h = nums3.size()-1;
        // float y = 2;
        
        while(l<=h){
            if(l==h){
                return nums3[l];
            }
            l++;
            h--;
        }
        float median = (nums3[l]+nums3[h])/2;
        return median;
        
        
    }
};