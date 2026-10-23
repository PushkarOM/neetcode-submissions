class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int l = -1, m = -1, n = -1;

        for (auto& t : triplets) {
        
            int x = t[0], y = t[1], z = t[2];
        
            if(x > target[0] || y > target[1] || z > target[2]) continue;
            l = max(l,x);
            m = max(m,y);
            n = max(n,z);
            
        }

        return target[0] == l && target[1] == m && target[2] == n ? true : false;
    }
};
