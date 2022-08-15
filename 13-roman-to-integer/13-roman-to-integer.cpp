class Solution {
public:
    int romanToInt(string s) {
        
        int first,second;
        int ans = 0;
        
        for(int i=0;i<s.size();i++){
            
            switch(s[i]){
                
                case 'M':
                    first = 1000;
                    break;

                 case 'D':
                    first = 500;
                    break;

                 case 'C':
                    first = 100;
                    break;

                 case 'L':
                    first = 50;
                    break;

                 case 'X':
                    first = 10;
                    break;

                case 'V':
                    first = 5;
                    break;

                case 'I':
                    first = 1;
                    break;
                
            }
            
            if(i+1!=s.size()){
                switch(s[i+1]){
                    case 'M':
                        second = 1000;
                        break;

                     case 'D':
                        second = 500;
                        break;

                     case 'C':
                        second = 100;
                        break;

                     case 'L':
                        second = 50;
                        break;

                     case 'X':
                        second = 10;
                        break;

                    case 'V':
                        second = 5;
                        break;

                    case 'I':
                        second = 1;
                        break;
                }
            }else{
                 ans += first;
                break;
            }
            
            if(first>=second){
                ans += first;
            }else{
                ans -= first;
            }
            
            
        }
        
        return ans;
        
    }
};