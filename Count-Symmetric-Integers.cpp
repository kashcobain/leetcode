class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;

        for(int i = low; i <= high; i++) {
            string p = to_string(i);
            int k = p.size();

            if(k % 2 != 0) continue; // odd length skip

            int sum1 = 0, sum2 = 0;
            for(int j = 0; j < k/2; j++) {
                sum1 += (p[j] - '0');
            }
            for(int j = k/2; j < k; j++) {
                sum2 += (p[j] - '0');
            }

            if(sum1 == sum2) {
                count++;
            }
        }

        return count; 
    }
};
