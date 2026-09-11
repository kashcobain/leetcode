class Solution {
public:
   bool isPossible(int mid, vector<int>& weights, int days){
    int req_day = 1, temp = mid;
    for(auto it:weights){
        if(it <= temp){
            temp -= it;
        }
        else{
            req_day++;
            if(it > mid)
                return false;
            temp = mid - it;
        }
    }
    if(req_day <= days)
        return true;
    return false;
}

int shipWithinDays(vector<int>& weights, int days) {
    int ans = -1;
    int low = INT_MIN, high = 0;
    for(auto it:weights){
        low = max(low, it);
        high += it;
    }
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(isPossible(mid, weights, days)){
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

};