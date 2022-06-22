class Solution {
public:
    
//     void permute(string nums,int l,int r){
        
//         if(l==r){
//             ans.push_back(nums);
//             return;
//         }
        
//         for(int i=l;i<=r;i++){
//             swap(nums[i],nums[l]);
//             permute(nums,l+1,r);
//             swap(nums[i],nums[l]);
//         }
        
//     }
    
    // vector<string> ans;
    
    string getPermutation(int n, int k) {
        
        string nums = "";
        
        for(int i=1;i<=n;i++){
            nums += to_string(i);
        }
        
//         permute(nums,0,nums.size()-1);
        
//         sort(ans.begin(),ans.end());
        
        
//         return ans[k-1];
        
        int i=1;
        
        while(i<k){
            next_permutation(nums.begin(),nums.end());
            i++;
        }
        
        return nums;
        
    }
};