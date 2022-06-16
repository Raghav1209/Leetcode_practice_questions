class Solution {
public:
    
    int merge(vector<int> &nums,int temp[],int left,int mid,int right){
        int i,j,k;
        int count = 0;
        int jj = mid+1;
        for(int i=left;i<=mid;i++){
            while(jj<=right && nums[i]>2LL*nums[jj]){
                jj++;
            }
            count = count + (jj-(mid+1));
        }
        
        i = left;
        j = mid+1;
        k = left;
        
        while(i<=mid && j<=right){
            if(nums[i]<=nums[j]){
                temp[k++] = nums[i++];
            }else{
                temp[k++] = nums[j++];
            }
        }
        
        while(i<=mid){
            temp[k++] = nums[i++];
        }
        
        while(j<=right){
            temp[k++] = nums[j++];
        }
        
        for(int i=left;i<=right;i++){
            nums[i] = temp[i]; 
        }
        
        return count;
        
    }
    
    int merge_sort(vector<int> &nums,int temp[],int left,int right){
        
        int count = 0;
        
        if(left<right){
            int mid = (left+right)/2;
            count += merge_sort(nums,temp,left,mid);
            count += merge_sort(nums,temp,mid+1,right);
            count += merge(nums,temp,left,mid,right);
        }
        
        return count;
        
    }
    
    int reversePairs(vector<int>& nums) {
        
        int n = nums.size();
        int temp[n];
        int ans = merge_sort(nums,temp,0,n-1);
        return ans;
        
    }
};