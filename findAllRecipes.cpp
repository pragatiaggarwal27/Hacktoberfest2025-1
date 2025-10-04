class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,vector<string>>mp;
        int n=recipes.size();
        unordered_map<string,int>indegree;
        for(int i=0;i<recipes.size();i++){
            for(auto it:ingredients[i]){
                mp[it].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
        }
        queue<string>q;
        for(auto it:supplies){
            q.push(it);
        }
        unordered_set<string>topo;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            for(auto it:mp[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                    topo.insert(it);
                }
            }
        }
        vector<string>ans;
        for(auto it:recipes){
            if(topo.count(it)){
                ans.push_back(it);
            }
        }
        return ans;
    }
};
