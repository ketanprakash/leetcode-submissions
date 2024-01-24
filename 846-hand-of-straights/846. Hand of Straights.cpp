class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        unordered_map<int, int> freq;

        for (int i = 0; i < hand.size(); i++){
            freq[hand[i]]++;
        }

        sort(hand.begin(), hand.end());
        for (int i = 0; i < hand.size(); i++){
            if (!freq.count(hand[i])) continue;
            for (int x = hand[i]; x < hand[i] + groupSize; x++){
                if (!freq.count(x)) return false;
                freq[x]--;
                if (freq[x] == 0) freq.erase(x);
            }
        }

        return true;
    }
};