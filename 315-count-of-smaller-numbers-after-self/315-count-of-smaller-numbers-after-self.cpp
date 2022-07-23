class Solution {
public:
    int arr[100001];
    void merge(vector<pair<int,int>> &pairs,int low,int mid,int high){
        int i = low;
        int j = mid;
        int k = 0;
        vector<pair<int,int>> temp(high-low+1);
        int count = 0;
        while(i<=mid-1 && j<=high){
            if(pairs[i].first<=pairs[j].first){
                arr[pairs[i].second] += count;
                temp[k++] = {pairs[i++]};
            }else{
                count++;
                temp[k++] = {pairs[j++]};
            }
        }
        
        while(i<=mid-1){
            arr[pairs[i].second] += count;
            temp[k++] = {pairs[i++]};
        }
        
        while(j<=high){
            // count++;
            temp[k++] = {pairs[j++]};
        }
        
        for(int i=0;i<k;i++){
            pairs[low++] = temp[i];
        }
        
    }
    
    void mergesort(vector<pair<int,int>> &pairs,int low,int high){
       int mid = (low+high)/2;
        if(low<high){
             
            mergesort(pairs,low,mid);
            mergesort(pairs,mid+1,high);
            merge(pairs,low,mid+1,high);
            
        }
        
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        
        vector<pair<int,int>> pairs;
        
        for(int i=0;i<nums.size();i++){
            pairs.push_back({nums[i],i});
        }
        int low = 0;
        int high = nums.size()-1;
        mergesort(pairs,low,high);
        
        vector<int> res(nums.size());
        
        for(int i=0;i<nums.size();i++){
            res[i] = arr[i];
        }
        
        return res;
        
    }
};