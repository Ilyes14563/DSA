#include <vector>
using namespace std;
class UnionFind{
    vector<int>size,parent;
    public:
        UnionFind(int n){
            size.resize(n,1);
            parent.resize(n);
            for(int i =0; i<n;i++){
                parent[i] = i;
            }
        }

        int findParent(int node){
            if(node==parent[node]) return node;
            else return parent[node] = findParent(parent[node]);
        }

        void Union(int u, int v){
            int parent_u = findParent(u);
            int parent_v = findParent(v);

            if(parent_v== parent_u)return;
            else if(size[parent_u] >= size[parent_v]){
                parent[parent_v] = parent_u;
                size[parent_u] += size[parent_v];
            }
            else{
                parent[parent_u] = parent_v;
                size[parent_v] += size[parent_u];
            }
        }
};
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool>answer(queries.size(),false);
        UnionFind uf(n);
        for(int i=n-1;i>0;i--){
            if(abs(nums[i]-nums[i-1]) <= maxDiff){
                uf.Union(i, i-1);
            }
        }
        for(int i=0; i<queries.size();i++){
            auto q= queries[i];
            if(uf.findParent(q[0]) == uf.findParent(q[1])) answer[i] = true;
        }
        return answer;
    }
};