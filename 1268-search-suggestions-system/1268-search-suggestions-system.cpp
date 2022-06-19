class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        vector<vector<string>> v;
        int n = searchWord.size();
        sort(products.begin(),products.end());
        
        // for(auto i : products){
        //     cout<<i<<" ";
        // }
        int j;
        for(int i=1;i<=n;i++){
            string word = searchWord.substr(0,i);
            // cout<<word<<endl;
            vector<string> vc;
            j = i;
            for(int i=1;i<=products.size();i++){
                string product = products[i-1];
                string w = product.substr(0,j);
                
                if(w==word){
                    vc.push_back(product);
                }
                
                if(vc.size()==3){
                    break;
                }
                
            }
            
            v.push_back(vc);
            
        }
        
        return v;
        
    }
};