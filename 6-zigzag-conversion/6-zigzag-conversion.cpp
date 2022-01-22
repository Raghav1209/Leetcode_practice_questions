class Solution {
public:
    string convert(string s, int n) {
        
        if(n==1){
            return s;
        }
        int len = s.length();
        vector<string> arr(n,"");
        bool counttype = true;
        int j = 0;
        for(int i=0;i<len;i++){
            arr[j] += s[i];
            if(counttype){
                j++;
            }else{
                j--;
            }
            if(counttype && j==n-1){
                counttype = false;
            }
            if(!counttype && j==0){
                counttype = true;
            }
        }
        string ans = "";
        for(int i=0;i<arr.size();i++){
            ans += arr[i];
        }
        return ans;
    }
};