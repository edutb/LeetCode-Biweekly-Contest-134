class Solution
{
public:
    long long count_and(vector<int> &nums, int k)
    {

        long long ans = 0;
        int l = 0;
        vector<int> bits(32, 0);

        for (int r = 0; r < nums.size(); r++)
        {

            for (int b = 0; b < 32; b++)
            {
                if (nums[r] & (1 << b))
                    bits[b]++;
            }

            for (; r - l + 1 > 0 && val(bits, r - l + 1) < k; l++)
            {

                for (int b = 0; b < 32; b++)
                {
                    if (nums[l] & (1 << b))
                        bits[b]--;
                }
            }

            ans += (r - l + 1);
        }
        return ans;
    }

    long long val(vector<int> &bits, int qtd)
    {

        long long num = 0;

        for (int b = 0; b < 32; b++)
        {
            if (bits[b] == qtd)
                num |= (1 << b);
        }

        return num;
    }

    long long countSubarrays(vector<int> &nums, int k)
    {
        return count_and(nums, k) - count_and(nums, k + 1);
    }
};