class Solution {
public:
    vector<int> temp;
    vector<int> original;
    
    Solution(vector<int>& nums) {
        original = nums;
        temp = nums;
    }
    
    vector<int> reset() {
        return original;
    }
    
    vector<int> shuffle() {
        for(int i=0;i<temp.size();i++){
            int x = rand()%original.size();
            swap(temp[i],temp[x]);
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