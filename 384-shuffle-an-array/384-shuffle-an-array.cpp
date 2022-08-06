class Solution {
public:
    vector<int> temp;
    vector<int> original;
    Solution(vector<int>& nums) {
        original = nums;
    }
    
    vector<int> reset() {
        return original;
    }
    
    vector<int> shuffle() {
        temp = original;
        
        
        
        
        for(int i=0;i<temp.size();i++){
            int k = rand()%original.size();
            swap(temp[i],temp[k]);
        }
        
        
        return temp;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */