class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        // reverse(nums.begin(),nums.end());
        int ans = 0;
        for(int i=0;i<n;i++){
            if(ans>=pow(2,floor(log2(nums[i])+1))-1){
                continue;
            }
            for(int j=0;j<n;j++){
                ans = max(nums[i]^nums[j],ans);
            }
        }
        return ans;
        
        // int ans=0,mask=0;
        // unordered_set<int>st;
        // for(int i=31;i>=0;i--){
        //     mask = mask | (1<<i);
        //     int temp=ans | (1<<i);
        //     for (int j = 0; j < nums.size(); j++) {
        //         int num = nums[j] & mask;
        //         if (st.find(temp ^ num)!=st.end()) {
        //             ans = temp;
        //             break;
        //         }
        //         st.insert(num);
        //     }
        //     st.clear();
        // }
        // return ans;
    }
};