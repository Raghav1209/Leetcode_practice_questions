class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i=0;
        int j = 0;
        vector<int> v;
        int nn = nums1.size();
        for(int i=nums1.size()-1;i>=0;i--){
            if(nums1[i]==0){
                 nums1.erase(nums1.begin()+i);  
            }else{
                break;
            }
        }
        
        for(int i=nums2.size()-1;i>=0;i--){
            if(nums2[i]==0){
                 nums2.erase(nums2.begin()+i);  
            }else{
                break;
            }
        }
        
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<nums2[j]){
                v.push_back(nums1[i]);
                i++;
            }else{
                v.push_back(nums2[j]);
                j++;
            }
        }
        
        while(i!=nums1.size()){
            v.push_back(nums1[i]);
            i++;
        }
        
        while(j!=nums2.size()){
            v.push_back(nums2[j]);
            j++;
        }
        
        nums1.clear();
        for(int i=0;i<v.size();i++){
            
                nums1.push_back(v[i]);
            }
           
        
    
        while(nums1.size()<nn){
            nums1.push_back(0);
        }
        
    }
        
    
};