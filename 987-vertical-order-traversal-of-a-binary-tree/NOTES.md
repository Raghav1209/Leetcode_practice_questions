}
}
}
vector<vector<int>> verticalTraversal(TreeNode* root) {
vector<vector<int>> ans;
map<int,vector<pair<int,int>>> mp;
solve(root,mp);
for(auto x : mp){
vector<pair<int,int>> vc = x.second;
sort(vc.begin(),vc.end(),mycmp);
vector<int> v;
for(auto x : vc){
v.push_back(x.second);
}
ans.push_back(v);
}
return ans;
}
};