class Solution {
public:
    vector<string> summaryRanges(vector<int>& arr) {
        
        int n = arr.size();
        vector<string> v;
        if(n==0){
            return v;
        }
        string str;
//         unordered_set<int> s;
        
//         for(int i=0;i<n;i++){
//             s.insert(arr[i]);
//         }
        int a = arr[0];
        int i = 1;
        int k = 1;
        while(i<n){
            int b = arr[i];
            if(a+k!=b){
                if(k==1){
                    str = to_string(a);
                }else{
                    str = to_string(a)+"->"+to_string(arr[i-1]);
                }
        
                v.push_back(str);
                str = "";
                a=arr[i];
                i++;
                k=1;
                continue;
            }
            i++;
            k++;
        }
        
       if(k==1){
            str = to_string(a);
        }else{
            str = to_string(a)+"->"+to_string(arr[i-1]);
        }
        v.push_back(str);
        
        return v;
        
    }
};