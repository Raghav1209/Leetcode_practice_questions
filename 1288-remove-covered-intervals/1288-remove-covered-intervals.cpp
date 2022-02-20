class Solution {
public:
    
    static bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
    {
        return (a.second < b.second);
    }
    
    int removeCoveredIntervals(vector<vector<int>>& arr) {
        
        // sort(arr.begin(),arr.end());
        
        // for(int i=0;i<arr.size();i++){
        //     for(int j=0;j<2;j++){
        //         cout<<arr[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        
        
        vector<pair<int,int>> v;
        
        vector<int> v1;
        vector<int> v2;
        
        for(int i=0;i<arr.size();i++){
            v1.push_back(arr[i][0]);
        }
        
        for(int i=0;i<arr.size();i++){
            v2.push_back(arr[i][1]);
        }
        
        
        
        for(int i=0;i<v1.size();i++){
            v.push_back(make_pair(v1[i],v2[i]));
        }
        
       sort(v.begin(),v.end(),sortbysec);
        
        // for(int i=0;i<v.size();i++){
        //     cout<<v[i].first<<" "<<v[i].second<<endl;
        // }
        
         int i = v.size()-1;
         int j ;
        int k = 1;
        // int x = 0;
        while(i>=1){
            j = i-1;
           while(j>=0){
                if(v[j].second<=v[i].second && v[j].first>=v[i].first){
                    v.erase(v.begin()+j);
                    i = v.size()-k;
                    j = i-1;
                }else if(v[i].second<=v[j].second && v[i].first>=v[j].first){
                    v.erase(v.begin()+i);
                    i=v.size()-1;
                    j=i-1;
                }
               else{
                    j = j-1;
                }
            }
            k++;
            i = v.size()-k;
            // j=i-1;
            
        }
        
        return v.size();
    }
        
};