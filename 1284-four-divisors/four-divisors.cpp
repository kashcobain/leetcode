class Solution {
public:
    int numdivisors(int n) {
        int count = 0;
        int ans = 0;

        for(int i = 1; i * i <= n; i++) {
            if(n % i == 0) {
                if(i * i == n) {
                    count++;
                    ans += i;
                } else {
                    count += 2;
                    ans += i;
                    ans += n / i;
                }
            }
        }

        if(count == 4) return ans;
        return 0;
    }

    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        for(int it : nums) {
            sum += numdivisors(it);
        }
        return sum;
    }
};
