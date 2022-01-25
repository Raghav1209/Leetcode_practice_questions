class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if(n<3){
            return false;
        }
        int partition = -1;
        for(int i=0;i<n-1;i++){
            if(arr[i+1]<arr[i]){
                partition=i;
                break;
            }else if(arr[i+1]==arr[i]){
                return false;
            }
        }
        if(partition==-1 || partition==0){
            return false;
        }
        
        for(int i=partition;i<n-1;i++){
            if(arr[i+1]>=arr[i]){
                return false;
            }
        }
        return true;
        
    }
};