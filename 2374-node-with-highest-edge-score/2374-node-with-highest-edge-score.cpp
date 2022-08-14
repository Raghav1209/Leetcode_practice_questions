class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long> hash(n+1, 0);
        
        for(int i=0;i<n;i++)
        {
            hash[edges[i]] += i;
        }
        
        
        long long int maxx = INT_MIN;
        int maxxIdx = -1;
        for(int i=0;i<hash.size();i++)
        {
            if(hash[i] > maxx)
            {
                maxx = hash[i];
                maxxIdx = i;
            }
        }
        return maxxIdx;
    }
};