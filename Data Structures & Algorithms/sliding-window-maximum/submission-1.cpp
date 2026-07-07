class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq; // {value, index}
        vector<int> ans;

        // Step 1: Build the first window
        for (int i = 0; i < k; i++) {
            pq.push({nums[i], i});
        }

        ans.push_back(pq.top().first);

        // Step 2: Slide the window
        for (int i = k; i < nums.size(); i++) {

            // Add the new element entering the window
            pq.push({nums[i], i});

            // Remove outdated elements
            while (!pq.empty() && pq.top().second <= i - k) {
                pq.pop();
            }

            // Current maximum
            ans.push_back(pq.top().first);
        }

        return ans;
    }
};