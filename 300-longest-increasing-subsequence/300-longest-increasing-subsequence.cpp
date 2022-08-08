class Solution {
public:
    
//     int find(vector<int> &tail,int l,int h,int x){
//         if(l<h){
//             int mid = (l+h)/2;
//             if(tail[mid]>=x){
//                 h = mid;
//             }else{
//                 l = mid+1;
//             }
//         }
//         return l;
//     }
    
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
//         vector<int> tail;
//         tail.push_back(nums[0]);
        
//         for(int i=1;i<n;i++){
//             if(nums[i]>=tail.back()){
//                 tail.push_back(nums[i]);
//             }
//             else{
//                 int c = find(tail,0,tail.size()-1,nums[i]);
//                 tail[c] = nums[i];
//             }
//         }
        
//         return tail.size();
        
        vector<int> lis(n);
        lis[0] = 1;
        for(int i=1;i<n;i++){
            lis[i] = 1;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    lis[i] = max(lis[j]+1,lis[i]);
                }
            }
        }
        int x = *max_element(lis.begin(),lis.end());
        return x;
    }
};