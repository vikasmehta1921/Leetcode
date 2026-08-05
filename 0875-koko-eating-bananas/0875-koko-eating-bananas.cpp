class Solution {
public:
    long long fun(vector<int>& piles, int speed) {
        long long totalhour = 0;

        for (int x : piles) {
            totalhour += (x + speed - 1) / speed;
        }
        return totalhour;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1; // min 1 can eat
        int high = *max_element(piles.begin(), piles.end());
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (fun(piles, mid) <= h) { // possible ans
                high = mid -1;
            } else {
                low = mid+1;
            }
        }
        return low;
    }
};