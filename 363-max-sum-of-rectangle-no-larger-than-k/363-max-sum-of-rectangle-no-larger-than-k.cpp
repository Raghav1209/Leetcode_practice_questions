class Solution {
public:
    
    int find_max(vector<int> &arr,int k){
        
        int curr_sum = 0;
        
        int maxx = INT_MIN;
        
        set<int> s;
        
        s.insert(0);
        
        for(int i=0;i<arr.size();i++){
            curr_sum += arr[i];
            
            auto it = s.lower_bound(curr_sum-k);
            
            if(it!=s.end()){
                maxx = max(curr_sum-*it,maxx);
            }
            
            s.insert(curr_sum);
            
        }
        
        return maxx;
        
    }
    
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        
        int n = matrix.size();
        
        int m = matrix[0].size();
        
        int maxx = INT_MIN;
        
        for(int start_row = 0;start_row<n;start_row++){
            vector<int> col_array(m,0);
            for(int end_row=start_row;end_row<n;end_row++){
                for(int i=0;i<m;i++){
                    col_array[i] += matrix[end_row][i];
                }
                
                int curr_max = find_max(col_array,k);
                
                maxx = max(maxx,curr_max);
                
            }
        }
        
        return maxx;
        
    }
};