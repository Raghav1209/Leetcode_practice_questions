unordered_map<int,int> mp;
int sum = 0;
int maxx = INT_MIN;
for(int i=0;i<nums.size();i++){
if(mp.find(nums[i])==mp.end()){
mp[nums[i]] = i;
sum += nums[i];
}else{
i = mp[nums[i]];
maxx = max(maxx,sum);
sum = 0;
mp.clear();
}
// cout<<sum<<" ";
}
maxx = max(maxx,sum);
return maxx;