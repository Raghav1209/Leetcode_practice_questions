class Solution {
public:
    void wiggleSort(vector<int>& arr) {
        
        int i=1;
        int j = arr.size()-1;
        
        sort(arr.begin(),arr.end());
        
        vector<int> res(arr.size());
        
        while(j>=0){
            
            if(i>=arr.size()){
                i=0;
            }
            
            res[i] = arr[j];
            j--;
            i += 2;
            
        }
        
        for(int i=0;i<arr.size();i++){
            arr[i] = res[i];
        }
        
    }
};