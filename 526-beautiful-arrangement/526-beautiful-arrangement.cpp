class Solution {
public:
    
    void permute(vector<int> &arr,int j){
        
        if(j==arr.size()){
            count++;
            return;
        }
        
        for(int i=j;i<arr.size();i++){
            swap(arr[i],arr[j]);
            if(arr[j]%(j+1)==0 || (j+1)%arr[j]==0){
                permute(arr,j+1);
            }
            swap(arr[i],arr[j]);
        }
        
    }
    
    int count = 0;
    
    int countArrangement(int n) {
        
        vector<int> arr(n,0);
        // int count = 0;
        for(int i=0;i<n;i++){
            arr[i] = i+1;
        }
        
        permute(arr,0);
        
        return count;
        
    }
};