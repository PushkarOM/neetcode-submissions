class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        vector<vector<int>> intervals(26,vector<int>(2,-1));
        vector<vector<int>> valid;
        vector<int> ans;

        for (int i = 0; i < s.length(); i++) {
            if (intervals[s[i] - 'a'][0] == -1)
                intervals[s[i] - 'a'][0] = i;

            intervals[s[i] - 'a'][1] = i;
        }

        for (auto& interval : intervals) {
            if (interval[0] != -1) {
                valid.push_back(interval);
            }
        }

        sort(valid.begin(), valid.end());

        // merge the intervals
        int start = valid[0][0];
        int end = valid[0][1];

        for (int i = 1; i < valid.size(); i++) {
            if (valid[i][0] <= end) {
                end = max(end, valid[i][1]);
            } else {
                ans.push_back(end - start + 1);
                start = valid[i][0];
                end = valid[i][1];
            }
        }

        ans.push_back(end - start + 1);
        return ans;
        
    }
};
