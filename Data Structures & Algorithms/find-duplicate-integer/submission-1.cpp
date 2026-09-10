class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Brute O(n^2) double loop to check if a element occurs more than once 
        // Better using hashmap to keep track of frequnecies
        // Optimal, using the flyds cycle detection algo, here
        // using the property than number in the array can go max up to N starting from 1
        // we can initilize slow pointer that moves using the current value as index
        // and fast pointer that move 
        // using the current number at the index it reacehs to i.e
        // slow = nums[slow]
        // fast = nums[nums[fast]]
        // as given the constraint this will never lead to index out of bound, 
        // and eventually slow and fast  will be equal

        int slow = nums[0];
        int fast = nums[0];

        // find a meeting point inside the cycle
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // find the entrance of the cycle = duplicate
        slow = nums[0];

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};

// Think of nums[i] as a pointer to the next index.
//
// Example:
// nums = [1,3,4,2,2]
//
// 0 -> 1 -> 3 -> 2 -> 4
//                ^    |
//                |____|
//
// Since values are in the range [1, n] but there are n+1 elements,
// at least two indices must point to the same value (duplicate).
// This creates a cycle in the "index -> nums[index]" graph.
//
// The duplicate number is exactly the entry point of that cycle.
// Floyd's Tortoise and Hare algorithm finds:
// 1. A meeting point inside the cycle.
// 2. The cycle entry (duplicate number).
//
// Time: O(n)
// Space: O(1)
