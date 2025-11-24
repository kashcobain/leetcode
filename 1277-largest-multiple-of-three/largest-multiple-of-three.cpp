class Solution {
public:
    // nums ka copy pass kar raha hai (thik hai), s ko reference se update karenge
    void stringbuild(vector<int> nums, string &s)
    {
        s.clear();
        int n = nums.size();
        if (n == 0) return;

        // nums ascending hai, hume largest number chahiye -> peeche se dalenge
        for (int i = n - 1; i >= 0; i--)
        {
            s += char(nums[i] + '0');
        }

        // agar sab digits 0 the, to answer "0" hona chahiye, "000..." nahi
        if (!s.empty() && s[0] == '0')
            s = "0";
    }

    string largestMultipleOfThree(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // ascending
        int m1a = INT_MAX, m1b = INT_MAX;  // 2 smallest with %3==1
        int m2a = INT_MAX, m2b = INT_MAX;  // 2 smallest with %3==2

        int sum = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            int v = nums[i];
            sum += v;
            int k = v % 3;

            if (k == 1)
            {
                if (v < m1a) {
                    m1b = m1a;
                    m1a = v;
                } else if (v < m1b) {
                    m1b = v;
                }
            }
            else if (k == 2)
            {
                if (v < m2a) {
                    m2b = m2a;
                    m2a = v;
                } else if (v < m2b) {
                    m2b = v;
                }
            }
        }

        string ans = "";

        // Case 1: already divisible by 3
        if (sum % 3 == 0)
        {
            stringbuild(nums, ans);
            return ans;
        }

        // Case 2: sum % 3 == 1
        if (sum % 3 == 1)
        {
            // Option 1: ek %3==1 wala sabse chhota digit hata de
            if (m1a != INT_MAX)
            {
                auto it = find(nums.begin(), nums.end(), m1a);
                if (it != nums.end()) nums.erase(it);
                stringbuild(nums, ans);
                return ans;
            }
            // Option 2: do %3==2 wale sabse chhote digits hata de
            else if (m2a != INT_MAX && m2b != INT_MAX)
            {
                auto it = find(nums.begin(), nums.end(), m2a);
                if (it != nums.end()) nums.erase(it);

                it = find(nums.begin(), nums.end(), m2b);
                if (it != nums.end()) nums.erase(it);

                stringbuild(nums, ans);
                return ans;
            }
            else
                return "";
        }

        // Case 3: sum % 3 == 2
        if (sum % 3 == 2)
        {
            // Option 1: ek %3==2 wala sabse chhota digit hata de
            if (m2a != INT_MAX)
            {
                auto it = find(nums.begin(), nums.end(), m2a);
                if (it != nums.end()) nums.erase(it);
                stringbuild(nums, ans);
                return ans;
            }
            // Option 2: do %3==1 wale sabse chhote digits hata de
            else if (m1a != INT_MAX && m1b != INT_MAX)
            {
                auto it = find(nums.begin(), nums.end(), m1a);
                if (it != nums.end()) nums.erase(it);

                it = find(nums.begin(), nums.end(), m1b);
                if (it != nums.end()) nums.erase(it);

                stringbuild(nums, ans);
                return ans;
            }
            else
                return "";
        }

        return "";
    }
};
