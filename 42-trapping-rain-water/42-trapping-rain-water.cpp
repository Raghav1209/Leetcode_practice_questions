class Solution {
public:
    int trap(vector<int>& height) {
        
        int Lmax = INT_MIN;
        int Rmax = INT_MIN;
        int l = 0;
        int r = height.size()-1;
        int water = 0;
        
        while(l<r){
            Lmax = max(Lmax,height[l]);
            Rmax = max(Rmax,height[r]);
            
            if(Lmax<Rmax){
                water += Lmax-height[l++];
            }else{
                water += Rmax-height[r--];
            }
            
        }
        
        return water;
        
    }
};