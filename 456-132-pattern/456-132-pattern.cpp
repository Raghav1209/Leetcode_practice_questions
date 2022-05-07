class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
//         int n = nums.size();
        
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 for(int k=j+1;k<n;k++){
//                     if((nums[i]<nums[j] && nums[k]<nums[j]) && (nums[i]<nums[k] && nums[i]                              <nums[j])){
//                         return true;
//                     }
//                 }
//             }
//         }
        
//         return false;
        
        stack<int> st;
        int s3 = INT_MIN;
        
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]<s3){
                return true;
            }else{
                while(!st.empty() && nums[i]>st.top()){
                    s3 = st.top();
                    st.pop();
                }
                
            }
            
            st.push(nums[i]);
            
        }
        
        return false;
        
    }
};