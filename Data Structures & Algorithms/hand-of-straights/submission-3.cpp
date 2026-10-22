
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        int n = hand.size();

        if (groupSize <= 0 || n % groupSize != 0) {
            return false;
        }

        if (groupSize == 1) {
            return true;
        }

        // create frequency map for each card avalilable
        map<int, int> freq;

        for (int card : hand) {
            freq[card]++;
        }

        for (auto& [card, count] : freq) {
            
            // if card's count == 0, continue to another one
            if (count == 0) continue;

            for (int i = 1; i < groupSize; i++) {
                // checking if next consecutive card from the starting card, exist inside the map with same or greater count
                if (freq[card + i] < count) {
                    return false;
                }

                freq[card + i] -= count;
            }
        }

        return true;
    }
};

// we are subtracting count, as if say 3 copies of the starting value are with us, we need to make 3 gropus with that starting value, anyhow.
/*
        Approach: Greedy + Frequency Map

        1. Count the frequency of every card using a map.
           The map stores cards in increasing order.

        2. Process cards from smallest to largest.
           If a card has count = 0, all its copies have
           already been used, so skip it.

        3. Suppose the current card is 'card' and its
           frequency is 'count'.

           Since this is the smallest remaining card,
           every copy of it must start a consecutive group.

           Therefore, we need 'count' copies of:
           card + 1, card + 2, ..., card + groupSize - 1.

        4. Check whether each required card has at least
           'count' copies.

           If not, return false because we cannot complete
           all the groups starting with the current card.

        5. Otherwise, subtract 'count' from each required
           card's frequency because those copies are used
           to complete the groups.

           We process all 'count' groups together instead
           of building each group individually.

        6. If every card is processed successfully, return true.

        Time Complexity: O(n log n)
        Space Complexity: O(n)
    */
