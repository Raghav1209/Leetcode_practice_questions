class Solution {
public:
    int bagOfTokensScore(vector<int>& t, int p) {
        
        int l = 0;
        int h = t.size()-1;
        sort(t.begin(),t.end());
        int count = 0;
        while(l<h){
            
            if(p>=t[l]){
                p -= t[l];
                l++;
                count++;
            }else if(count>=1 && p+t[h]>=t[l]){
                p += t[h];
                h--;
                count--;
            }else{
                break;
            }
        }
        
        while(l<h+1 && p>=t[l]){
            p -= t[l];
            l++;
            count++;
        }
        
        return count;
        
        // int used_tok = t.size()-h;
        
       
        
    }
};