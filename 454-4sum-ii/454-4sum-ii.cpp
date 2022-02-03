class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
        unordered_map<int,int> mp;
        int n = nums1.size();
        int count=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mp[nums1[i]+nums2[j]]++;
            }
        }
        
        for(int k=0;k<n;k++){
            for(int l=0;l<n;l++){
                if(mp.find(-1*(nums3[k]+nums4[l]))!=mp.end()){
                    count += mp[-1*(nums3[k]+nums4[l])];
                }
            }
        }
       
        
        return count;
        
    }
};