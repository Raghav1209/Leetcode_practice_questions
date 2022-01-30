class Solution {
public:

    
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        // while(k>n){
        //     // reverse(nums.begin(),nums.end());
        //     k = k-n;
        // }
        int x = n-k;
        reverse(nums.begin(),nums.end()-k);
        reverse(nums.begin()+x,nums.end());
        reverse(nums.begin(),nums.end());
    }
};