class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int> mp;
        int k = 0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        
        unordered_map<int,int>  :: iterator it;
        
        for(it=mp.begin();it!=mp.end();it++){
            if(it->second > 2){
                it->second=2;
            }
        }
        
        vector<int> nums2;
        
        // for(auto x : mp){
        //     cout<<x.first<<"->"<<x.second<<endl;
        // }
        
        for(auto x : mp){
            while(x.second){
                nums2.push_back(x.first);
                x.second--;
            }
            
        }
        k = nums2.size();
        sort(nums2.begin(),nums2.end());
        
        for(int i=0;i<nums2.size();i++){
            nums[i]=nums2[i];
        }
        
        return k;
        
    }
};