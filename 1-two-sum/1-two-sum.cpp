class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       vector<int> nums2 = nums;
        sort(nums2.begin(),nums2.end());
        vector<int> v;
        int l = 0;
        int h = nums2.size()-1;
        int first,second;
        while(l<h){
            int sum = nums2[l] + nums2[h];
            if(target==sum){
                first = nums2[l];
                second = nums2[h];
                break;
            }else if(target>sum){
                l++;
            }else{
                h--;
            }
        }
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==first){
                v.push_back(i);
                break;
            }
        }
        
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]==second){
                v.push_back(i);
                break;
            }
        }
        return v;
        
       
    }
};