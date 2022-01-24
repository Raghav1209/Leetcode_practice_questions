class Solution {
public:
    bool detectCapitalUse(string word) {
        int flag=0;
        int n = word.length();
           if(word[0]>='a' && word[0]<='z'){
               for(int i=1;i<n;i++){
                   if(word[i]>='A' && word[i]<='Z'){
                       return false;
                   }
               }
               // return true;
           }else{
               if(word[n-1]>='A' && word[n-1]<='Z'){
                   flag = 0;
               }else{
                   flag = 1;
               }
               for(int i=n-1;i>=1;i--){
                   if(word[i]>='a' && word[i]<='z'){
                       if(flag==0){
                           return false;
                       }
                       // flag = 1;
                   }else{
                       if(flag==1){
                           return false;
                       }
                       // flag=0;
                   }
               }
           }
            return true;
    }
};