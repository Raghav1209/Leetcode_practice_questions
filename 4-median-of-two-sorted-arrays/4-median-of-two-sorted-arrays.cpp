class Solution {
public:
    
    double find(vector<int> &a1,vector<int> &a2){
        int begin1,end1;
        begin1 = 0;
        
        end1 = a1.size();
        
        while(begin1<=end1){
            int i1 = (begin1+end1)/2;
            int i2 = (a1.size()+a2.size()+1)/2 - i1;
            
            int max1 = (i1==0) ? INT_MIN : a1[i1-1];
            int min1 = (i1==a1.size()) ? INT_MAX : a1[i1];
            
            int max2 = (i2==0) ? INT_MIN : a2[i2-1];
            int min2 = (i2==a2.size()) ? INT_MAX : a2[i2];
            
            if(max1<=min2 && max2<=min1){
                
                if((a1.size()+a2.size())%2==0){
                    return ((double) max(max1,max2) + min(min1,min2) )/2;
                }else{
                    return ((double) max(max1,max2));
                }
                
            }else if(max1 > min2){
                end1 = i1-1;
            }else{
                begin1 = i1+1;
            }
            
        }
        
        return (double) 0;
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums1.size()<nums2.size()){
            return find(nums1,nums2);
        }else{
            return find(nums2,nums1);
        }
        
    }
};