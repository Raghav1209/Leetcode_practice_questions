class Solution {
public:
    int trap(vector<int>& hei) {
        
        int l = 0;
        int h = hei.size()-1;
        
        int Lmax = INT_MIN;
        int Rmax = INT_MIN;
        int sum = 0;
        while(l<=h)
        {
            Lmax = max(Lmax,hei[l]);
            Rmax = max(Rmax,hei[h]);
            
            if(Lmax<Rmax){
                sum += (Lmax-hei[l++]);
            }else{
                sum += (Rmax-hei[h--]);
            }
            
            
        }
        
        return sum;
        
    }
};