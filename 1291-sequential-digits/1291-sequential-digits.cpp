class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        
        vector<int> v;
        
        int lowlen = to_string(low).length();
        int highlen = to_string(high).length();
        string digits = "123456789";
        
        for(int i=lowlen;i<=highlen;i++){
            for(int j=0;j<10-i;j++){
                int num = stoi(digits.substr(j,i));
                if(num>=low && num<=high){
                    v.push_back(num);
                }
            }
        }
        
        
        return v;
    }
};