class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
        int n = nums.size();
//         set<int> s;
        int count = 0;
//         for(int i=0;i<n;i++){
//             s.insert(nums[i]);
//         }
         
//         for(auto x : s){
//             int  k = n-1;
//             while(k>=2){
//                 int h = k-1;
//                 int l = 0;
//                 while(l<h){
//                     int sum = nums[l]+nums[h]+nums[k];
//                     if(sum>x){
//                         h--;
//                     }else if(sum<x){
//                         l++;
//                     }else{
//                         count++;
//                         l++;
//                         h--;
//                     }
//                 }
//                 k--;
//             }
//         }
//         return count;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    for(int l=k+1;l<n;l++){
                        if(nums[i]+nums[j]+nums[k]==nums[l]){
                            count++;
                        }
                    }
                }
            }
        }
        return count;
       
        
    }
};